using ll = long long;

class SegmentTree {
private:
    vector<ll> tree;
    ll n;

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll left = query(2 * node + 1, start, mid, l, r);
        ll right = query(2 * node + 2, mid + 1, end, l, r);
        return max(left, right);
    }

    void update(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            if (value > tree[node]) {
                tree[node] = value;
            }
        } else {
            ll mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(ll maxi) {
        n = maxi + 1;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    ll query(ll l, ll r) {
        if (l > r) return 0;
        return query(0, 0, n - 1, l, r);
    }

    void update(ll idx, ll value) {
        update(0, 0, n - 1, idx, value);
    }
};

const int INC = 1E4;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        for(auto &c:nums) c += INC;

        // Coordinate-compression-start
        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (int& num : nums) {
            num = lower_bound(comp.begin(), comp.end(), num) - comp.begin();
        }
        ll maxi = comp.size() - 1;
        // Coordinate-compression-end

        SegmentTree t(maxi);
        ll res=1;

        for(int i=0;i<n;i++){
            ll num=nums[i];
            ll lisLengthThatEndsAtI=t.query(0,num-1) + 1;
            t.update(num,lisLengthThatEndsAtI);
            res=max(res,lisLengthThatEndsAtI);
        }

        return res;
    }
};
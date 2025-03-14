class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2]; 
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left | right;
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

int calcBestOrFromLToLast(int start,int n,SegmentTree &t,int k){
    int lo=start;
    int hi=n-1;
    int mini=INT_MAX;

    while(lo <= hi){
        int mid=lo + ((hi-lo)>>1);
        int orFromStartToMid=t.query(start,mid);
        mini=min(mini,abs(k-orFromStartToMid));

        if(orFromStartToMid < k) lo=mid+1;
        else hi=mid-1;
    }

    return mini;
}


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();

        SegmentTree t(nums);

        int mini=INT_MAX;
        for(int l=0;l<n;l++){
            mini=min(mini,calcBestOrFromLToLast(l,n,t,k));
        }

        return mini;
    }
};
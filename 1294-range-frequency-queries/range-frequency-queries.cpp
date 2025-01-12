using ll=long long;

class SegmentTree
{
private:
    vector<unordered_map<ll, ll>> tree;
    vector<ll> arr;
    ll n;

    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node][arr[start]]++;
        }
        else
        {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            for (auto it = tree[2 * node + 1].begin(); it != tree[2 * node + 1].end(); ++it)
            {
                tree[node][it->first] += it->second;
            }
            for (auto it = tree[2 * node + 2].begin(); it != tree[2 * node + 2].end(); ++it)
            {
                tree[node][it->first] += it->second;
            }
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r, ll value)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node].count(value) ? tree[node][value] : 0;
        }
        ll mid = (start + end) / 2;
        ll left = query(2 * node + 1, start, mid, l, r, value);
        ll right = query(2 * node + 2, mid + 1, end, l, r, value);
        return left + right;
    }

    void update(ll node, ll start, ll end, ll idx, ll new_value)
    {
        if (start == end)
        {
            tree[node].clear();
            tree[node][new_value]++;
            arr[start] = new_value;
        }
        else
        {
            ll mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(2 * node + 1, start, mid, idx, new_value);
            }
            else
            {
                update(2 * node + 2, mid + 1, end, idx, new_value);
            }

            tree[node].clear();
            for (auto it = tree[2 * node + 1].begin(); it != tree[2 * node + 1].end(); ++it)
            {
                tree[node][it->first] += it->second;
            }
            for (auto it = tree[2 * node + 2].begin(); it != tree[2 * node + 2].end(); ++it)
            {
                tree[node][it->first] += it->second;
            }
        }
    }

public:
    SegmentTree(const vector<ll> &input) : n(input.size()), arr(input)
    {
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    ll query(ll l, ll r, ll value)
    {
        return query(0, 0, n - 1, l, r, value);
    }

    void update(ll idx, ll new_value)
    {
        update(0, 0, n - 1, idx, new_value);
    }
};

class RangeFreqQuery {
public:
    SegmentTree* t = nullptr;

    RangeFreqQuery(vector<int>& v) {
        vector<ll>v_ll(v.begin(), v.end());
        t=new SegmentTree(v_ll);
    }
    
    int query(int left, int right, int value) {
        return t->query(left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
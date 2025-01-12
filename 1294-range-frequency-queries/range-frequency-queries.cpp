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

    unordered_map<ll, ll> range_freq(ll node, ll start, ll end, ll l, ll r)
    {
        if (r < start || l > end)
        {
            return {};
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        unordered_map<ll, ll> left_map = range_freq(2 * node + 1, start, mid, l, r);
        unordered_map<ll, ll> right_map = range_freq(2 * node + 2, mid + 1, end, l, r);

        unordered_map<ll, ll> result;
        for (auto it = left_map.begin(); it != left_map.end(); ++it)
        {
            result[it->first] += it->second;
        }
        for (auto it = right_map.begin(); it != right_map.end(); ++it)
        {
            result[it->first] += it->second;
        }
        return result;
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

    ll distinct_count(ll l, ll r)
    {
        unordered_map<ll, ll> freq_map = range_freq(0, 0, n - 1, l, r);
        return freq_map.size();
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
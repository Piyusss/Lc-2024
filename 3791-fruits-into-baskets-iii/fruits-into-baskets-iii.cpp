using ll=long long;

class SegmentTree
{
private:
    vector<ll> tree;
    vector<int> arr;
    ll n;

    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(ll node, ll start, ll end, ll idx, ll value)
    {
        if (start == end)
        {
            tree[node] = value;
            arr[start] = value;
        }
        else
        {
            ll mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(2 * node + 1, start, mid, idx, value);
            }
            else
            {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    ll first_above(ll node, ll start, ll end, ll x, ll l)
    {
        if (tree[node] < x || end < l)
        {
            return -1;
        }
        if (start == end)
        {
            return start;
        }
        ll mid = (start + end) / 2;
        if (mid >= l && tree[2 * node + 1] >= x)
        {
            ll left_result = first_above(2 * node + 1, start, mid, x, l);
            if (left_result != -1)
                return left_result;
        }
        return first_above(2 * node + 2, mid + 1, end, x, l);
    }

public:
    SegmentTree(const vector<int> &input)
    {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(ll idx, ll value)
    {
        update(0, 0, n - 1, idx, value);
    }

    ll first_above(ll x, ll l)
    {
        return first_above(0, 0, n - 1, x, l);
    }
};


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();

        SegmentTree t(baskets);
        int cnt=0;

        for(int i=0;i<n;i++){
            int curFruitReq=fruits[i];
            int findWhichBasket=t.first_above(curFruitReq,0);

            if(findWhichBasket==-1)cnt+=1;
            else t.update(findWhichBasket,0);
        }

        return cnt; // :) :) :)-easy-peasy
    }
};
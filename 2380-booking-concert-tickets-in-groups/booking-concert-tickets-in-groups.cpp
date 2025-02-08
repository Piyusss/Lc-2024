using ll=long long;

class SegmentTree
{
private:
    vector<ll> tree;
    vector<ll> arr;
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
    SegmentTree(const vector<ll> &input)
    {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void upd(ll idx, ll value)
    {
        update(0, 0, n - 1, idx, value);
    }

    ll first_above(ll x, ll l)
    {
        return first_above(0, 0, n - 1, x, l);
    }
};

class SegmentTree2 {
private:
    vector<ll> tree;
    vector<ll> arr;
    ll n;

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; 
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll left = query(2 * node + 1, start, mid, l, r);
        ll right = query(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }

    void update(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            tree[node] = value;
        } else {
            ll mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree2(const vector<ll>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(ll idx, ll value) {
        update(0, 0, n - 1, idx, value);
    }
};

class BookMyShow {
public:

ll tot_seat;
ll n;
vector<ll>seats_left;
vector<ll>can_start_inThisRow;
SegmentTree* t=nullptr;
SegmentTree2* t2=nullptr;


    BookMyShow(int N, int m) {
        n=N;
        tot_seat=m;
        seats_left.resize(n,m);
        can_start_inThisRow.resize(n,0);
        t=new SegmentTree(seats_left);
        t2=new SegmentTree2(seats_left);
    }
    
    vector<int> gather(int k, int maxRow) {
        vector<int>res(2);
        ll smallest_row_for_gather=t->first_above(k,0);
        if(smallest_row_for_gather > maxRow || smallest_row_for_gather<0){
            return{};
        }
        else{
            res[0]=smallest_row_for_gather;
            res[1]=can_start_inThisRow[res[0]];

            seats_left[res[0]] -= k;
            can_start_inThisRow[res[0]] += k;

            t->upd(res[0],seats_left[res[0]]);//point-update
            t2->update(res[0],seats_left[res[0]]);//point-update
        }

        return res;
    }
    
    bool scatter(int k, int maxRow) {
        ll prefixSeatSum=t2->query(0,maxRow);//range-sum
        if(prefixSeatSum < k){
            return 0;
        }
        else{
            //can-be-accomodated
            for(ll i=0;i<=maxRow && k>0;i++){
                ll rem=k-seats_left[i];
                if(rem>=0){
                    //this-ith-row-is-utilized-completely
                    can_start_inThisRow[i] += seats_left[i];
                    k -= seats_left[i];
                    t->upd(i,0);
                    t2->update(i,0);
                    seats_left[i]=0;
                }
                else{
                    //this-row-is-partially-filled
                    can_start_inThisRow[i] += k;
                    t->upd(i,seats_left[i]-k);
                    t2->update(i,seats_left[i]-k);
                    seats_left[i] -= k;
                    k=0;
                    break;
                }
            }
        }

        return 1;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
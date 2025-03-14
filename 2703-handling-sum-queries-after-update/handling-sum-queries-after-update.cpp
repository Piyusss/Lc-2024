using ll=long long;

class LazySegtree{
private:

    int n;
    vector<ll> tree;
    vector<bool> lazy;
    
    void build(const vector<int>& arr, int v, int l, int r){
        if(l == r) {
            tree[v] = arr[l];
        } else {
            int m = (l+r)/2;
            build(arr, 2*v, l, m);
            build(arr, 2*v+1, m+1, r);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }
    
    void pushDown(int v, int l, int r) {
        if(lazy[v]) {
            int m = (l+r)/2;
            lazy[2*v] = !lazy[2*v];
            lazy[2*v+1] = !lazy[2*v+1];

            tree[2*v] = (m - l + 1) - tree[2*v];
            tree[2*v+1] = (r - m) - tree[2*v+1];
            lazy[v] = false;
        }
    }
    
    void update(int v, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            tree[v] = (r - l + 1) - tree[v];
            lazy[v] = !lazy[v];
            return;
        }
        pushDown(v, l, r);
        int m = (l+r)/2;
        update(2*v, l, m, ql, qr);
        update(2*v+1, m+1, r, ql, qr);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
    
    ll query(int v, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return tree[v];
        pushDown(v, l, r);
        int m = (l+r)/2;
        return query(2*v, l, m, ql, qr) + query(2*v+1, m+1, r, ql, qr);
    }

public:
    LazySegtree(const vector<int>& arr){
        n = arr.size();
        tree.resize(4*n, 0);
        lazy.assign(4*n, false);
        build(arr, 1, 0, n-1);
    }
    
    void update(int ql, int qr) {
        update(1, 0, n-1, ql, qr);
    }
    
    ll query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
};

class Solution {
public:
    vector<ll> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();

        vector<ll>res;
        LazySegtree t(nums1);
        ll sum2=accumulate(nums2.begin(),nums2.end(),(ll)0);
        
        for(auto &q:queries){
            int type=q[0];

            if(type == 1){
                int l=q[1];
                int r=q[2];
                t.update(l,r);
            }
            else if(type == 2){
                int p=q[1];
                ll ones=t.query(0,n-1);
                sum2 += p*ones;
            }
            else res.push_back(sum2);
        }

        return res;
    }
};

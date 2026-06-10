class SegmentTree {
public:
    vector<int>t;
    bool mn;

    SegmentTree(vector<int>& a,bool b){
        mn=b;
        int n=a.size();
        t.resize(4*n);
        build(0,0,n-1,a);
    }

    void build(int i,int l,int r,vector<int>& a){
        if(l==r){
            t[i]=a[l];
            return;
        }

        int m=(l+r)>>1;

        build(2*i+1,l,m,a);
        build(2*i+2,m+1,r,a);

        if(mn) t[i]=min(t[2*i+1],t[2*i+2]);
        else t[i]=max(t[2*i+1],t[2*i+2]);
    }

    int qry(int ql,int qr,int i,int l,int r){
        if(r<ql||l>qr) return mn?INT_MAX:INT_MIN;

        if(ql<=l&&r<=qr) return t[i];

        int m=(l+r)>>1;

        int x=qry(ql,qr,2*i+1,l,m);
        int y=qry(ql,qr,2*i+2,m+1,r);

        return mn?min(x,y):max(x,y);
    }

    int query(int l,int r,int n){
        return qry(l,r,0,0,n-1);
    }
};

long long f(int l,int r,SegmentTree& mn,SegmentTree& mx,int n){
    return 1LL*mx.query(l,r,n)-mn.query(l,r,n);
}

using ll=long long;

class Solution {
public:

    long long maxTotalValue(vector<int>& a,int k) {
        int n=a.size();

        SegmentTree mn(a,1),mx(a,0);

        priority_queue<tuple<ll,int,int>> pq;
        for(int l=0;l<n;l++) pq.push({f(l,n-1,mn,mx,n),l,n-1});

        ll ans=0;
        while(k-- && !pq.empty()){
            auto [v,l,r]=pq.top();
            pq.pop();

            ans+=v;
            if(r-1>=l) pq.push({f(l,r-1,mn,mx,n),l,r-1});
        }

        return ans;
    }
};
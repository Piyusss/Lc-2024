using ll=long long;

class Solution {
public:

    int k;
    struct T{
        int p,c[5];
    };

    vector<T>s;

    T mg(T a,T b){
        T r={a.p*b.p%k,{}};

        for(int i=0;i<k;i++){
            r.c[i]+=a.c[i];
            r.c[a.p*i%k]+=b.c[i];
        }

        return r;
    }

    void up(int p,int l,int r,int x,int v){
        if(l==r){
            s[p]={v%k,{}};
            s[p].c[s[p].p]=1;
            return;
        }

        int m=(l+r)/2;

        if(x<=m) up(p*2,l,m,x,v);
        else up(p*2+1,m+1,r,x,v);

        s[p]=mg(s[p*2],s[p*2+1]);
    }

    T qr(int p,int l,int r,int x){
        if(l>=x) return s[p];
        int m=(l+r)/2;
        if(x>m) return qr(p*2+1,m+1,r,x);
        return mg(qr(p*2,l,m,x),s[p*2+1]);
    }

    vector<int> resultArray(vector<int>& a,int k,vector<vector<int>>& q) {
        this->k=k;

        int n=a.size();
        s.resize(4*n);

        for(int i=0;i<n;i++) up(1,0,n-1,i,a[i]);
        vector<int>ans;

        for(auto &x:q){
            up(1,0,n-1,x[0],x[1]);
            ans.push_back(qr(1,0,n-1,x[2]).c[x[3]]);
        }

        return ans;
    }
};
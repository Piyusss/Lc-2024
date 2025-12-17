using ll=long long;

class Solution{

    vector<int>a;
    ll neg=-1E14;
    ll d[1005][505][3];

    ll g(int i,int k,int s){
        if(i==a.size())return s?neg:0;

        ll &r=d[i][k][s];
        if(r!=-1)return r;

        r=g(i+1,k,s);
        ll v=a[i];
        
        if(s==0){
            r=max(r,g(i+1,k,1)-v);
            r=max(r,g(i+1,k,2)+v);
        }
        else if(k){
            if(s==1)r=max(r,g(i+1,k-1,0)+v);
            else r=max(r,g(i+1,k-1,0)-v);
        }

        return r;
    }

public:
    long long maximumProfit(vector<int>& p, int k) {
        memset(d,-1,sizeof(d));
        a=p;
        return g(0,k,0);
    }
};

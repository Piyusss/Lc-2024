using ll=long long;

class Solution {
public:

    ll f(int x,int y,int s){
        if(!y) return x;

        if(x==s) return s+y;
        if(y==s) return 2LL*s+(s-x);

        return 3LL*s+(s-y);
    }

    bool ok(int k,ll per,int d,vector<ll>&v){
        int n=v.size()/2;
        vector<int>nxt(2*n);

        int j=0;
        for(int i=0;i<2*n;i++){
            while(j<2*n && v[j]<v[i]+d) j++;
            nxt[i]=j;
        }

        for(int i=0;i<n;i++){
            int cnt=1,idx=i;
            while(cnt<k){
                idx=nxt[idx];
                if(idx>=i+n) break;
                cnt++;
            }

            if(cnt==k&&v[i]+per>=v[idx]+d) return 777;
        }

        return 0;
    }

    int maxDistance(int s,vector<vector<int>>& p,int k){
        vector<ll>v;
        ll per=4LL*s;

        for(auto &x:p) v.push_back(f(x[0],x[1],s));
        sort(v.begin(),v.end());

        int n=v.size();
        vector<ll>d(2*n);

        for(int i=0;i<n;i++){
            d[i]=v[i];
            d[i+n]=v[i]+per;
        }

        int l=0,r=per/k,ans=0;
        while(l<=r){
            int m=(l+r)/2;
            if(ok(k,per,m,d)){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }

        return ans;
    }
};
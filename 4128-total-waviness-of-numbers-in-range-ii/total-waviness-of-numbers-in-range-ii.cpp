using ll=long long;

class Solution {
public:

    ll dp[16][12][12];
    vector<int>d;
    int n;

    ll cnt(int p,bool t){
        if(p==n) return 1;

        if(!t){
            ll r=1;
            for(int i=p;i<n;i++) r*=10;
            return r;
        }

        ll r=0;
        for(int i=p;i<n;i++) r=r*10+d[i];
        return r+1;
    }

    ll f(int p,int a,int b,bool t,bool st){
        if(p==n) return 0;

        if(!t && st && dp[p][a+1][b+1]!=-1) return dp[p][a+1][b+1];

        int ub=t?d[p]:9,lb=0;
        ll r=0;

        for(int x=lb;x<=ub;x++){
            bool nt=t&&(x==ub);

            if(!st && x==0) r+=f(p+1,-1,-1,nt,0);
            else{
                int w=0;
                if(b!=-1&&a!=-1) if((b>a&&b>x) || (b<a&&b<x)) w=1;
                if(w) r+=cnt(p+1,nt);

                r+=f(p+1,b,x,nt,1);
            }
        }

        if(!t&&st) dp[p][a+1][b+1]=r;
        return r;
    }

    ll f(ll x){
        if(x<=0) return 0;

        d.clear();

        string s=to_string(x);
        n=s.size();

        for(auto &c:s) d.push_back(c-'0');

        memset(dp,-1,sizeof(dp));
        return f(0,-1,-1,1,0);
    }

    long long totalWaviness(long long l,long long r) {
        return f(r)-f(l-1);
    }
};
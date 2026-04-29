using ll=long long;

using vll=vector<ll>;
using vvll=vector<vll>;
using vvvll=vector<vvll>;

ll f(int col,int fill,int curr,int n,vvll &pref,vvvll &dp){
    if(col==n-1){
        if(curr==1) return 0;
        return fill?pref[col][fill-1]:0;
    }
    
	if(dp[col][fill][curr]!=-1) return dp[col][fill][curr];
	 
    ll ans=f(col+1,n,0,n,pref,dp);

    if(curr==0){	 		   
        for(int take=1;take<=n;take++){
            if(take<=fill){
                ll tot=pref[col][fill-1];
                ll untake=fill-take;

                if(untake) tot-=pref[col][untake-1];                
                ans=max(ans,tot+f(col+1,untake,0,n,pref,dp));
        	}
        	else ans=max(ans,pref[col][take-1] + f(col+1,take,1,n,pref,dp));
        }
    }

    else{
         for(int take=1;fill+take<=n;take++){
            ll d=fill+take;
            ll tot=pref[col][d-1] ;
            if(fill) tot-=pref[col][fill-1] ;
            ans=max(ans,tot+f(col+1,d,1,n,pref,dp));
        }
    }

    return dp[col][fill][curr]=ans;
}


class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
    	int n=grid.size();

		vvll pref(n,vll(n));
		vvvll dp(n+1,vvll(n+1,vll(2,-1)));
			
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) pref[j][i]=grid[i][j]+(i?pref[j][i-1]:0);
		return f(0,0,1,n,pref,dp);		 
    }
};
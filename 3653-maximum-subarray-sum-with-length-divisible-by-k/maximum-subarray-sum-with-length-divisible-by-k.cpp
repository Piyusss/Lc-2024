using ll=long long;

class Solution {
public:
    ll maxSubarraySum(vector<int>& a, int k) {
        int n=a.size();
        vector<ll>p(n+1);

        for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];
        ll ans=LLONG_MIN;

        for(int s=0;s<k;s++){
            ll cur=(s+k<=n) ? p[s+k]-p[s] : LLONG_MIN;
            ans=max(ans,cur);

            for(int i=s+2*k;i<=n;i+=k){
                ll x=p[i]-p[i-k];
                cur=max(cur+x,x);
                ans=max(ans,cur);
            }
        }
        
        return ans;
    }
};
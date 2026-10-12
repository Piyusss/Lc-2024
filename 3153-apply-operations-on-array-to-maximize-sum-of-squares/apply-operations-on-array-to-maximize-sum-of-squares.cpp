using ll=long long;
const ll mod=1E9+7;

class Solution {
public:
    int maxSum(vector<int>& a, int k) {
        int c[31]={};
        for(auto &x:a) for(int b=0;b<31;b++) if(x>>b&1) c[b]++;

        ll ans=0;
        for(int i=0;i<k;i++){
            ll x=0;

            for(int b=0;b<31;b++){
                if(c[b]){
                    x|=1LL<<b;
                    c[b]--;
                }
            }

            ans=(ans+x*x)%mod;
        }

        return ans;
    }
};
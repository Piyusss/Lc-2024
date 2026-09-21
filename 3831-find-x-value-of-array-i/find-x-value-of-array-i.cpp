using ll=long long;

class Solution {
public:
    vector<long long> resultArray(vector<int>&a, int k) {
        for(auto &x:a) x%=k;
        vector<ll>ans(k),dp(k);

        for(auto &x:a){
            vector<ll>ndp(k);

            ndp[x]++;
            for(int i=0;i<k;i++) if(dp[i]) ndp[i*x%k]+=dp[i];

            dp=ndp;
            for(int i=0;i<k;i++) ans[i]+=dp[i];
        }

        return ans;
    }
};
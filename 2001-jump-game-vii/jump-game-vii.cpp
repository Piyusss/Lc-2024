class Solution {
public:
    bool canReach(string s,int mn,int mx) {
        int n=s.size();

        if(s[n-1]=='1') return 0;
        vector<bool>dp(n);
        dp[0]=1;

        int reach=0;

        for(int i=1;i<n;i++){
            if(i-mn>=0) reach+=dp[i-mn];
            if(i-mx-1>=0) reach-=dp[i-mx-1];

            if(reach>0 && s[i]=='0') dp[i]=1;
        }

        return dp[n-1];
    }
};
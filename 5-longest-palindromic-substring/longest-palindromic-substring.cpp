class Solution {
public:

int dp[10001][1001];

bool isPal(string &s,int i,int j){
    if(i>=j)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==s[j])return dp[i][j]= isPal(s,i+1,j-1);
    return dp[i][j]= 0;
}
    string longestPalindrome(string s) {
        int n=s.size();

        memset(dp,-1,sizeof(dp));
        
        int max_len=0;
        int sp=0;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j)){
                    if(max_len<j-i+1){
                        max_len=j-i+1;
                        sp=i;
                    }
                }
            }
         }
         return s.substr(sp,max_len);
    }
};
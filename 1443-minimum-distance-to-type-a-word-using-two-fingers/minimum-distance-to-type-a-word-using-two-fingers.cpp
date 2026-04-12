class Solution {
public:

    int dp[301][27][27];

    int d(int a,int b){
        if(a==26 || b==26) return 0;
        return abs(a/6-b/6)+abs(a%6-b%6);
    }

    int f(int i,int x,int y,string &s){
        if(i==s.size()) return 0;
        if(dp[i][x][y]!=-1) return dp[i][x][y];

        int c=s[i]-'A',a=d(x,c)+f(i+1,c,y,s),b=d(y,c)+f(i+1,x,c,s);
        return dp[i][x][y]=min(a,b);
    }

    int minimumDistance(string s){
        memset(dp,-1,sizeof(dp));
        return f(0,26,26,s);
    }
};
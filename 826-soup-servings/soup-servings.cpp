class Solution {
public:

vector<vector<int>>options={{100,0},{75,25},{50,50},{25,75}};
vector<vector<double>>dp;

double f(int soupALeft,int soupBLeft){
    if(soupALeft<=0 && soupBLeft<=0)return 0.5;
    if(soupALeft<=0)return 1.0;
    if(soupBLeft<=0)return 0.0;

    if(dp[soupALeft][soupBLeft]!=-1.0)return dp[soupALeft][soupBLeft];
    
    double res=0.0;
    for(auto &it:options){
        int A=it[0];
        int B=it[1];
        res+= f(soupALeft-A,soupBLeft-B);
    }

    return dp[soupALeft][soupBLeft]= 0.25*res;
}
    double soupServings(int n){
        if(n>=5000)return 1;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return f(n,n);
    }
};
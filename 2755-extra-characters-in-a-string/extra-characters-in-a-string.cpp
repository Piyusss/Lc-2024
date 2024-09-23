class Solution {
public:

int n;
int dp[100];

int f(int i,string &s,unordered_set<string> &st){
    if(i>=n)return 0;

    if(dp[i]!=-1)return dp[i];

    int res=1+f(i+1,s,st);

    for(int j=i;j<n;j++){
        string cur=s.substr(i,j-i+1);
        if(st.count(cur)) res=min(res,f(j+1,s,st));
    }
    
    return dp[i]=res;
}
    int minExtraChar(string s, vector<string>& d){
        n=s.size();
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st(d.begin(),d.end());
        return f(0,s,st);
    }
};
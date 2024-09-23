class Solution {
public:

int n;
int dp[51];

int f(int i,string &s,unordered_set<string> &st){
    if(i>=n)return 0;

    if(dp[i]!=-1)return dp[i];

    string curStr="";
    int mini=n;
    for(int j=i;j<n;j++){
        curStr+=s[j];
        int curExtra=(st.find(curStr)==st.end()) ? curStr.size() : 0;
        int nextExtra=f(j+1,s,st);
        int tot=curExtra + nextExtra;
        mini = min(mini,tot);
    }
    
    return dp[i]=mini;
}
    int minExtraChar(string s, vector<string>& d){
        n=s.size();
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st(d.begin(),d.end());
        return f(0,s,st);
    }
};
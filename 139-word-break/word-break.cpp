class Solution {
public:

bool f(string s,unordered_set<string>&st,vector<int>&dp,int idx){
    if(idx==s.size())return 1;
    if(dp[idx]!=-1)return dp[idx];

    for(int i=idx;i<s.size();i++){
        if(st.count(s.substr(idx,i+1-idx)) &&  f(s,st,dp,i+1)){
            dp[idx]=1;
            return 1;
        }
    }
    return dp[idx]=0;
}

    bool wordBreak(string s, vector<string>& wordDict){
        vector<int>dp(s.size(),-1);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return f(s,st,dp,0);
    }
};
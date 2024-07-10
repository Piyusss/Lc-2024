class Solution {
public:
static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

bool f(string &s1,string &s2){
    if(s1.size()!=s2.size()+1)return 0;

    int first=0;
    int second=0;
    while(first<s1.size()){
        if(s1[first]==s2[second]){first++;second++;}
        else first++;
    }
    if(first==s1.size() && second==s2.size())return 1;
    return 0;
}
    int longestStrChain(vector<string>& arr){
        int n=arr.size();

        sort(arr.begin(),arr.end(),comp);
        
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(f(arr[i],arr[prev])){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
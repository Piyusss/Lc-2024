class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    long long i=0;long long j=0;long long n=s.length();
    unordered_map<char,long long>mp;long long ans=0;
    while(j<n){
        if(mp.find(s[j])!=mp.end())i=max(i,mp[s[j]]+1);
        mp[s[j]]=j;
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
    }
};
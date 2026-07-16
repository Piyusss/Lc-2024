class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0||n==1) return n;

        unordered_map<char,int>mp;
        int res=0,i=0;

        for(int j=0;j<n;j++){
            char ch=s[j];
            
            if(mp.find(ch)!=mp.end()) i=max(i,mp[ch]+1);

            mp[ch]=j;
            res=max(res,j-i+1);
        }

        return res;
    }
};
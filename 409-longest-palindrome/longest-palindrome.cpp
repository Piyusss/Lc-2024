class Solution {
public:
    int longestPalindrome(string s){
         int n=s.size();
         map<char,int>mp;
         for(auto it:s)mp[it]++;
         int cnt=0,flag=0;
         //now
            for(auto it:mp){
                cnt+=it.second;
                if((it.second&1)){
                    cnt--;
                    flag=1;
                }
            }
        return flag ? ++cnt : cnt;
    }
};
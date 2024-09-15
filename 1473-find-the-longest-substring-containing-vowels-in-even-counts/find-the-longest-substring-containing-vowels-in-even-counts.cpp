class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();

        unordered_map<int,int>mp;
        mp[0]=-1;

        int res=0,bitmask=0;
        for(int i=0;i<n;i++){
            s[i]=='a'  ? (bitmask=bitmask ^ 1<<0) :
            (s[i]=='e' ? (bitmask=bitmask ^ 1<<1) :
            (s[i]=='i' ? (bitmask=bitmask ^ 1<<2) :
            (s[i]=='o' ? (bitmask=bitmask ^ 1<<3) :
            (s[i]=='u' ? (bitmask=bitmask ^ 1<<4) : (0==0)))));

            mp.find(bitmask)!=mp.end() ? res=max(res,i-mp[bitmask]) : mp[bitmask]=i;
        }

        return res;
        
    }
};
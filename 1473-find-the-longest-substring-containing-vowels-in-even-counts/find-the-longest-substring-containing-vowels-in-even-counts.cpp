class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();

        unordered_map<int,int>mp;
        mp[0]=-1;
        int res=0;
        int bitmask=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a') bitmask=bitmask ^ (1<<0);
            else if(s[i]=='e') bitmask=bitmask ^ (1<<1);
            else if(s[i]=='i') bitmask=bitmask ^ (1<<2);
            else if(s[i]=='o') bitmask=bitmask ^ (1<<3);
            else if(s[i]=='u') bitmask=bitmask ^ (1<<4);

            if(mp.find(bitmask)!=mp.end())res=max(res,i-mp[bitmask]);
            else mp[bitmask]=i;
        }

        return res;
    }
};
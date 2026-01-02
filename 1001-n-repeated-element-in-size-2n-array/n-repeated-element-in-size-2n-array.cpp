class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();

        map<int,int>mp;
        for(auto &c:nums) mp[c]++;
        
        for(auto &c:nums) if(mp[c]==(n>>1)) return c;
        return -1;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;

        for(auto it:mp)if(it.second>=2)return it.first;

        return -1;
    }
};
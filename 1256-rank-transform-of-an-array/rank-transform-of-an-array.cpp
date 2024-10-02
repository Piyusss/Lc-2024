class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums){
        int n=nums.size(),mark=1;

        vector<int>orig=nums;
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(auto &it:nums) if(mp.find(it)==mp.end())mp[it]=mark++;

        vector<int>res;
        for(auto &it:orig) res.push_back(mp[it]);
        return res;
    }
};
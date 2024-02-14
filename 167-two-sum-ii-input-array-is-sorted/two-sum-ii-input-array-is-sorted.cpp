class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(t-nums[i])!=mp.end()){
                return {mp[t-nums[i]],i+1};
            }
            mp[nums[i]]=i+1;
        }
        return {};
    }
};
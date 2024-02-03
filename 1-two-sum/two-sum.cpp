class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int targ){
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(targ-nums[i])!=mp.end()){
                return {i,mp[targ-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
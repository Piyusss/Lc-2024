class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t){
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.count(t-nums[i])){
                return {i,mp[t-nums[i]]};
            }
            mp[nums[i]]=i;
        }

        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int targ){
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums.size() ; j++){
                if(i!=j && nums[i]+nums[j]==targ){
                    return {i,j};
                }
            }
        
        }
        return {};
    }
};
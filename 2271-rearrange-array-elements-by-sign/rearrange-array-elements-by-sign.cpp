class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>0){
                v1.push_back(nums[i]);
            }
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]<0){
                v2.push_back(nums[i]);
            }
        }
        nums.clear();

        for(int i=0 ; i<v1.size() ; i++){
            nums.push_back(v1[i]);
            nums.push_back(v2[i]);
        }
        return nums;
    }
};
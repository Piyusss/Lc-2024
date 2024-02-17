class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cntZero=count(nums.begin(),nums.end(),0);
        vector<int>ans;
        for(auto it:nums){
            if(it){
                ans.push_back(it);
            }
        }
        while(cntZero--)ans.push_back(0);
        nums=ans;
    }
};
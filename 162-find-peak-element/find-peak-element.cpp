class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int n=nums.size();
        if(n==1) return 0;

        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        }

        return nums[1]>nums[0] ? n-1 : 0;
    }
};
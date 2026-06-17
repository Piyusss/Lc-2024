class Solution {
public:

    int f(vector<int>&nums){
        int l=0,r=nums.size()-1;
        while(l<r){
            int m=l+((r-l)>>1);
            if(nums[m]>nums[r]) l=m+1;
            else r=m;
        }
        return l;
    }

    int findMin(vector<int>& nums) {
        int pivot=f(nums);
        return nums[pivot];
    }
};
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

    int f2(int l,int r,vector<int>&nums,int t){
        while(l<=r){
            int m=l+((r-l)>>1);
            if(nums[m]==t) return m;
            else if(nums[m]<t) l=m+1;
            else r=m-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=f(nums);

        if(target>=nums[pivot] && target<=nums[n-1]) return f2(pivot,n-1,nums,target);
        else return f2(0,pivot-1,nums,target);

        return -1;
    }
};
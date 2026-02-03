class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();

        int idx1=-1,idx2=-1,one=0,two=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1] || nums[i]==nums[i+1]) return 0;
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                one++;
                idx1=i;
            }
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                two++;
                idx2=i;
            }
        }

        if(one==1 && two==1 && idx1<idx2) return 1;
        return 0;
    }
};
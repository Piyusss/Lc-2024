class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        vector<int>prefixSum(n);
        int tot=accumulate(nums.begin(),nums.end(),0);
        int prefix=0;

        for(int i=0;i<n;i++){
            int leftSum=prefix;
            int rightSum=tot-leftSum-nums[i];
            ans[i]=(nums[i]*i)-leftSum+rightSum-(nums[i]*(n-i-1));
            prefix+=nums[i];
        }
        return ans;
    }
};
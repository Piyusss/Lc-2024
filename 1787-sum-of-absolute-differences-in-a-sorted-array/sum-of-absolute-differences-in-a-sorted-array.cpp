class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        vector<int>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            int leftSum=prefixSum[i]-nums[i];
            int rightSum=prefixSum[n-1]-prefixSum[i];
            ans[i]=(nums[i]*i)-leftSum+rightSum-(nums[i]*(n-i-1));
        }
        return ans;
    }
};
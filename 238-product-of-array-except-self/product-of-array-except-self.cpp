class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n,1);
        ans[0]=1;

        int tempForwardProduct=1;
        int tempBackwardProduct=1;

        for(int i=0;i<n;i++){
            ans[i]*=tempForwardProduct;
            tempForwardProduct*=nums[i];

            ans[n-i-1]*=tempBackwardProduct;
            tempBackwardProduct*=nums[n-i-1];
        }

        return ans;

    }
};
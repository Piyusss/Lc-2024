class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);

        vector<int>prefixProductFront(n);
        vector<int>prefixProductBack(n);

        int tempForwardProduct=1;
        int tempBackwardProduct=1;

        for(int i=0;i<n;i++){
            prefixProductFront[i]=tempForwardProduct*nums[i];
            tempForwardProduct*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            prefixProductBack[i]=tempBackwardProduct*nums[i];
            tempBackwardProduct*=nums[i];
        }

        for(int i=0;i<n;i++){
            int prLeft=1,prRight=1;
            if(i)prLeft=prefixProductFront[i-1];
            if(i<n-1)prRight=prefixProductBack[i+1];
            ans[i]=prLeft*prRight;
        }

        return ans;

    }
};
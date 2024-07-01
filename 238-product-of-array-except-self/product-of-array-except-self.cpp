class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);

        int pr=1;int prp=1;int cnt=0;
        for(int i=0;i<n;i++){
            pr*=nums[i];
            if(nums[i])prp*=nums[i];
            if(nums[i]==0)cnt++;
        }

        for(int i=0;i<n;i++){
            if(nums[i])ans[i]=pr/nums[i];
            else{
                if(cnt>1)ans[i]=0;
                else ans[i]=prp;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
            if(i&1)ans[i]=ans[i/2]+1;
            else ans[i]=ans[i/2];

            if(ans[i]==k)sum+=nums[i];
        }
        return sum;
    }
};
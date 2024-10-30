class Solution {
public:

void f(vector<int>&nums,int n,vector<int>&dp){
    //LIS_it_izz
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
}

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();

        vector<int>dpLeft(n,1),dpRight(n,1);

        f(nums,n,dpLeft);
        reverse(nums.begin(),nums.end());
        f(nums,n,dpRight);

        int res=INT_MAX;
        reverse(dpRight.begin(),dpRight.end());
        for(int i=1;i<n-1;i++){
            int mountainArray= dpLeft[i] + dpRight[i] - 1;
            if(mountainArray >= 3 && dpLeft[i]>=2 && dpRight[i]>=2) res=min(res,n-mountainArray);
        }

        return res;

    }
};
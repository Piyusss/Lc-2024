class Solution {
public:

int flag=0;
void f(vector<int>&nums,int n,vector<int>&dp){
    //LIS_it_izz
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    
    reverse(nums.begin(),nums.end());
    if(flag++) reverse(dp.begin(),dp.end());
}

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();

        vector<int>dpLeft(n,1),dpRight(n,1);

        f(nums,n,dpLeft);
        f(nums,n,dpRight);

        int res=INT_MAX;
        for(int i=1;i<n-1;i++){
            int mountainArraySize= dpLeft[i] + dpRight[i] - 1;
            if(mountainArraySize >= 3 && dpLeft[i]>=2 && dpRight[i]>=2) res=min(res,n-mountainArraySize);
        }

        return res;

    }
};
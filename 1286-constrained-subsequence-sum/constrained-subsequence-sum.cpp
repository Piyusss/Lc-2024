class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>dp(n);
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});

        for(int i=0;i<n;i++)dp[i]=nums[i];

        int res=dp[0];

        for(int i=1;i<n;i++){
            while(!pq.empty() && i-pq.top().second>k)pq.pop();
            dp[i]=max(dp[i],nums[i]+pq.top().first);
            pq.push({dp[i],i});
            res=max(res,dp[i]);
        }
        return res;
    }
};
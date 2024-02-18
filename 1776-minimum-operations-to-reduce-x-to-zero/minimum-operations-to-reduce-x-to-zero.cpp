class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        unordered_map<int,int>mp;
        int sum=0;

        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }

        if(sum<x)return -1;

        int need=sum-x;
        int maxi=INT_MIN;

        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(mp.find(sum-need)!=mp.end()){
                maxi=max(maxi,i-mp[sum-need]);
            }
        }
        if(maxi==INT_MIN)return -1;
        return n-maxi;
    }
};
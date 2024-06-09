class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mp;

        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int rem=sum%k;
            if(rem<0)rem+=k;

            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};
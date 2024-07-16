class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;

        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1)cnt++;
            if(mp.count(cnt-k)){
                ans+=mp[cnt-k];
            }
            mp[cnt]++;
        }

        return ans;

    }
};
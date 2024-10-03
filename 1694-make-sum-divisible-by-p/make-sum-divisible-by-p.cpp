class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();

        int problem=0;
        for(int i=0;i<n;i++)problem=(problem+nums[i])%p;

        unordered_map<int,int>mp;
        if(!problem) return 0;

        int temp=0,res=n;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            temp = (temp + nums[i]) % p;
            int dif=(temp-problem+p) % p;
            if(mp.find(dif)!=mp.end()) res=min(res,i-mp[dif]);

            mp[temp]=i;
        }

        return res==n ? -1 : res;
    }
};
class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]=i;
        //now
        int i=0,j=mp[nums[0]];
        int cnt=1;

        while(i<n){
            if(i>j)cnt=(cnt*2)%M;
            j=max(j,mp[nums[i]]);
            i++;
        }
        return cnt;
    }
};
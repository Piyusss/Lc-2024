class Solution {
public:
    int numSubarraysWithSum(vector<int>&v,int k) {
        map<int,int>mp;mp[0]=1;
        int prefixSum=0,cnt=0;
        for(int i=0;i<v.size();i++){
            prefixSum+=v[i];
            cnt+=mp[prefixSum-k];
            mp[prefixSum]++;
        }
        return cnt;
    }
};
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long idealSum=0;
        long long cnt=0;
        long long mini=INT_MAX;

        for(auto it:nums){
            long long xoredVal=it^k;
            if(xoredVal>it){
                idealSum+=xoredVal;
                cnt++;
            }
            else{
                idealSum+=it;
            }
            long long dif=abs(xoredVal-it);
            mini=min(mini,dif);
        }


        if(!(cnt&1))return idealSum;
        return idealSum-mini;
    }
};
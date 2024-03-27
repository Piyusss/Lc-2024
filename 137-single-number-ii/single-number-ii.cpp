class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int ones=0,zeros=0;
            for(int j=0;j<n;j++){
                if(nums[j]& (1<<i) )ones++;
                else zeros++;
            }
            if(ones%3!=0)ans=ans | (1<<i);
        }
        return ans;
    }
};
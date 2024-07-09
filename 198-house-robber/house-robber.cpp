class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        
        int prev=nums[0];int prev2=0;
        for(int idx=1;idx<=n-1;idx++){
            int cur=max(idx>=2 ? nums[idx]+prev2 : nums[idx] , prev);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};
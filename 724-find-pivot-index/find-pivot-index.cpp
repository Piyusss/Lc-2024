class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int prefix=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int tl=prefix-nums[i];
            int tr=total-prefix;
            if(tl==tr){
                ans=i;break;
            }
        }
        return ans;
    }
};
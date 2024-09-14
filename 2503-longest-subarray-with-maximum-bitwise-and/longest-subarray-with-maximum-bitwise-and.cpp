class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi_el=*max_element(nums.begin(),nums.end());

        int cnt=0,maxi=0;
        for(int i=0;i<n;i++){
            nums[i]==maxi_el ? cnt++ : maxi=max(maxi,cnt)-(cnt=0);
        }

        maxi=max(maxi,cnt);
        return maxi;

    }
};
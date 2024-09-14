class Solution {
public:
    int longestSubarray(vector<int>& nums){
        int n=nums.size() , cnt=0,maxi=0 , maxi_el=*max_element(nums.begin(),nums.end()) , i=0;
        while(i<n) nums[i++]==maxi_el ? cnt++ : maxi=max(maxi,cnt)-(cnt=0);
        return max(maxi,cnt);
    }
};
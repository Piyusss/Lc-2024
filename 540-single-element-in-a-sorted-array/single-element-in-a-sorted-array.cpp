class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor_r=0;
        for(auto it:nums)xor_r^=it;
        return xor_r;
    }
};
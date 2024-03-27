class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(k==__builtin_popcount(i))sum+=nums[i];
        }
        return sum;
    }
};
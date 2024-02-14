class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(i-j)<=k){
                    if(nums[i]==nums[j])return 1;
                }
                else break;
            }
        }
        return 0;
    }
};
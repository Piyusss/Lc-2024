class Solution {
public:

    bool check(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] > nums[i+1]) return 0;
        }
        return 1;
    }

    bool canSortArray(vector<int>& nums) {
        int n=nums.size(),move=0;

        vector<int>count(101);
        for(auto &it : nums) count[move++] = __builtin_popcount(it);

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++) {
                if(count[j] == count[j - 1] && nums[j] < nums[j-1]) {
                    swap(nums[j],nums[j - 1]);
                }
            }
            if(check(nums)) return 1;
        }

        return 0;

    }
};
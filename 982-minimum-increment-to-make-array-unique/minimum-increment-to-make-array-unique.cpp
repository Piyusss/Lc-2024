class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=1;i<=nums.size()-1;i++){
            if(nums[i]<=nums[i-1]){
                ans+=(nums[i-1]-nums[i]+1);
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};
//1 2 3 4 5 7
// ans=6
// i=5
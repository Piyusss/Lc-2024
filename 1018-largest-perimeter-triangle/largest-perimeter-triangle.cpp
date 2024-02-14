class Solution {
public:
    bool check(int i,int j,int k){
        if(i+j>k)return 1;
        return 0;
    }
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            int sum=nums[i]+nums[i-1]+nums[i-2];
            if(check(nums[i-2],nums[i-1],nums[i]))return sum;
        }
        return 0;
    }
};
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        
        int counter=n-1,flag=0;
        while(counter--){
            for(int i=0;i<n-1-flag;i++){
                int sum=(nums[i]+nums[i+1])%10;
                nums[i]=sum;
            }
            flag++;
        }

        return nums[0];
    }
};
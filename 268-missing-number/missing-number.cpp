class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1=0;
        int sum2=0;

        for(int i=0 ; i<nums.size() ; i++){
            sum1+=nums[i];
        }

        sum2=(nums.size())*(nums.size()+1)/2;

        return(sum2-sum1);
    }
};
class Solution {
public:
    int candy(vector<int>& nums){
        int n=nums.size();
        int sum=1,i=1;

        while(i<n){
            if(nums[i]==nums[i-1]){
                sum++;i++;
                continue;
            }

            int peak=1;
            while(i<n && nums[i]>nums[i-1]){
                peak++;sum+=peak;i++;
            }

            int down=1;
            while(i<n && nums[i]<nums[i-1]){
                sum+=down;
                down++;i++;
            }
            if(down>peak)sum+=down-peak;
        }
        return sum;
    }
};
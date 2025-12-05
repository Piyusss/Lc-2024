class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();

        int totalSum=accumulate(nums.begin(),nums.end(),0);

        int cnt=0;
        int leftHalfSum=0,rightHalfSum=0;

        for(int i=0;i<n-1;i++){
            leftHalfSum += nums[i];
            rightHalfSum = (totalSum-leftHalfSum);

            cout<<leftHalfSum-rightHalfSum<<endl;
            if(abs(leftHalfSum-rightHalfSum) % 2 == 0) cnt++;
        }

        return cnt;
    }
};
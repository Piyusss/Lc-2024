class Solution {
public:
    int minPairSum(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //now
        int i=0,j=n-1,maxi=INT_MIN;
        while(i<j){
            maxi=max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};
//[4,1,5,1,2,5,1,5,5,4]->[1,1,1,2,4,4,5,5,5,5]
// 6 6 6 7 8 
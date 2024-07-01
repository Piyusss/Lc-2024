class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int start=-1,end=-1;

        for(int i=0;i<nums.size();i++){
            if(sum==0)start=i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                end=i;
            }
            if(sum<0)sum=0;
        }
        for(int i=start;i<=end;i++)cout<<nums[i]<<" ";
        return maxi;
    }
};
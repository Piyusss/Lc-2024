class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>res(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int id=(i+nums[i])%n;
                res[i]=nums[id];
            }
            else if(nums[i]<0){
                int id=(i+n-(abs(nums[i])%n))%n;
                res[i]=nums[id];
            }
            else res[i]=nums[i];
        }

        return res;
    }
};
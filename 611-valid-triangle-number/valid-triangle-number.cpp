class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int cnt=0;

        for(int k=2;k<n;k++){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    cnt += j-i;
                    j--;
                }
                else i++;
            }
        }

        return cnt;
    }
};
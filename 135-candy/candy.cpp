class Solution {
public:
    int candy(vector<int>& nums){
        int n=nums.size();

        vector<int>left(n),right(n);
        left[0]=right[n-1]=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                left[i]=left[i-1]+1;
            }
            else left[i]=1;
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                right[i]=right[i+1]+1;
            }
            else right[i]=1;
        }

        int cnt=0;

        for(int i=0;i<n;i++)cnt+=max(left[i],right[i]);

        return cnt;
    }
};
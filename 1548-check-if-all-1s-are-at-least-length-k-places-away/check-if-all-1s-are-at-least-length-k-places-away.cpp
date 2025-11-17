class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();

        int start=0,end=0,flag=1,flag2=1;
        for(int i=0;i<n;i++){
            if(nums[i] && flag){
                start=i;
                flag=0;
            }
            if(nums[n-i-1] && flag2){
                end=n-i-1;
                flag2=0;
            }
        }

        int cnt=0;
        for(int i=start+1;i<=end;i++){
            if(nums[i]==1){
                if(cnt<k) return 0;
                cnt=0;
            }
            else cnt++;
        }
        
        return 1;
    }
};
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();

        int start=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                start=i;
                break;
            }
        }

        int end=0;
        for(int i=n-1;i>=start;i--){
            if(nums[i]==1){
                end=i;
                break;
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
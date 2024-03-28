class Solution {
public:
    int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%M;
        }
        int i=0,j=n-1,cnt=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                cnt=(cnt%M + power[j-i])%M;
                i++;
            }
            else j--;
        }
        return cnt;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long n=nums.size();
        long long pr=1,cnt=0;
        for(long long i=0;i<n;i++){
            pr=1;
            for(long long j=i;j<n;j++){
                pr=pr*nums[j];
                if(pr<k)cnt++;
                else break;
            }
        }
        return cnt;
    }
};
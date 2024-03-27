class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long n=nums.size();
        long long pr=1,cnt=0,j=0,i=0;
        if(k<=1)return 0;
        while(j<n){
            pr*=nums[j];
            while(pr>=k){
                pr/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};
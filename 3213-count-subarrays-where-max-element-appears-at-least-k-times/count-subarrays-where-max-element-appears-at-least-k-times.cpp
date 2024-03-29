class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        long long maxE=*max_element(nums.begin(),nums.end());
        //now
        long long i=0,j=0,ans=0,cnt=0;
        while(j<n){
            if(nums[j]==maxE)cnt++;
            while(cnt>=k){
                ans+=n-j;
                if(nums[i]==maxE)cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
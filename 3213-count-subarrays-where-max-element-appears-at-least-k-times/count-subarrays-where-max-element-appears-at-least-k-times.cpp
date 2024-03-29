class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        long long maxE=*max_element(nums.begin(),nums.end());
        //now
        long long ans=0;
        vector<long long>ind;
        for(int i=0;i<n;i++){
            if(nums[i]==maxE)ind.push_back(i);
            if(ind.size()>=k){
                ans+=ind[ind.size()-k]+1;
            }
        }
        return ans;
    }
};
//1 3 2 3 2
class Solution {
public:

#define ll long long
    int chalkReplacer(vector<int>& nums, int k){
        ll n=nums.size();

        ll s=accumulate(nums.begin(),nums.end(),0LL);
        k%=s;

        for(ll i=0;i<n;i++) {
            if(k<nums[i])return i;
            k-=nums[i];
        }

        return -1;
    }
};
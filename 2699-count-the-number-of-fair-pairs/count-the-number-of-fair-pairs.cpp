class Solution {
public:

#define ll long long

    ll countFairPairs(vector<int>& nums, int lower, int upper){
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll res=0;

        for(ll i=1;i<=n;i++){
            ll l=lower_bound(nums.begin()+i,nums.end(),lower-nums[i-1])-nums.begin();
            ll r=upper_bound(nums.begin()+i,nums.end(),upper-nums[i-1])-nums.begin();
            cout<<l<<" "<<r-1<<endl;
            res += (r-l);
        }

        return res;
    }
};
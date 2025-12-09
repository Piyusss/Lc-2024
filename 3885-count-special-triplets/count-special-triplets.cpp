using ll=long long;
const int M=1E9+7;

class Solution {
public:

    int specialTriplets(vector<int>& nums) {
        int n=nums.size();

        unordered_map<ll,ll>mp1,mp2;
        mp1[nums[0]]=1;

        for(int i=n-1;i>=2;i--) mp2[nums[i]]++;

        ll cnt=0;
        for(int i=1;i<=n-2;i++){
            ll cur=nums[i];
            ll need=cur<<1;

            cnt += (mp1[need]*mp2[need]);
            cnt %= M;

            mp1[cur]++;
            mp2[nums[i+1]]--;
        }

        return cnt;
    }
};
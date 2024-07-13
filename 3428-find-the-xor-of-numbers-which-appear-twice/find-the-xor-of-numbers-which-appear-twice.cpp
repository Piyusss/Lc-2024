class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans=0;

        map<int,int>mp;

        for(auto it:nums)mp[it]++;

        for(auto it:nums){
            if(mp[it]==2)ans^=it;
            mp[it]++;
        }

        return ans;
    }
};
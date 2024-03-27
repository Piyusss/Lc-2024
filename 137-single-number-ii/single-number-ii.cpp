class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        //now
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==1)return nums[i];
        }
        return -1;
    }
};
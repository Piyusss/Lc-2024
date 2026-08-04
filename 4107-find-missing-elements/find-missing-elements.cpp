class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>res;
        unordered_map<int,bool>mp;

        for(int i=0;i<n;i++) mp[nums[i]]=1;
        for(int i=nums[0];i<=nums[n-1];i++) if(!mp[i]) res.push_back(i);
        
        return res;
    }
};
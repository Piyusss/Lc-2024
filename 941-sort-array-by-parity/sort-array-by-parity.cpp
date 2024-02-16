class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        vector<int>ans;
        for(auto it:nums){
            if(!(it&1))ans.push_back(it);
        }
        for(auto it:nums){
            if((it&1))ans.push_back(it);
        }
        return ans;
    }
};
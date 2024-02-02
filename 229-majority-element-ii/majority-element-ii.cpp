class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int req=floor(n/3);
        vector<int>ans;set<int>st;
        for(auto it:nums)st.insert(it);
        for(auto it:st){
            if(count(nums.begin(),nums.end(),it)>req){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
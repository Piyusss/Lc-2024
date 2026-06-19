class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>st;

        for(auto &c:nums){
            if(st.count(c)) return 1;
            st.insert(c);
        }
        
        return 0;
    }
};
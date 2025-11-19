class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &c:nums) st.insert(c);

        int search=original;
        while(1){
            if(find(st.begin(),st.end(),search)!=st.end()){
                search *= 2;
            }
            else{
                return search;
            }
        }

        return -1;
    }
};
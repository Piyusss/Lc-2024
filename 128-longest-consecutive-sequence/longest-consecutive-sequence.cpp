class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums)st.insert(it);
        int maxi=0;
        for(auto it:nums){
            if(!st.count(it-1)){
                int curNum=it;
                int curStreak=1;
                while(st.count(curNum+1)){
                    curNum+=1;
                    curStreak+=1;
                }
                maxi=max(maxi,curStreak);
            }
        }
        return maxi;
    }
};
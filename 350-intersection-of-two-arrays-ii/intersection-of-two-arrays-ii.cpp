class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        unordered_map<int,int>mp1,mp2;

        for(auto it:nums1)mp1[it]++;
        for(auto it:nums2)mp2[it]++;

        for(auto it:nums1){
            if(mp1[it] && mp2[it]){
                ans.push_back(it);
                mp1[it]--;
                mp2[it]--;
            }
        }

        return ans;
    }
};
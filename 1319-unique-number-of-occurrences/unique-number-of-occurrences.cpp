class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        for(auto it:ans){
            if(count(ans.begin(),ans.end(),it)!=1)return 0;
        }
        return 1;
    }
};
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int n=v.size();
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            mp[v[i]].push_back(i);
            if(v[i]==mp[v[i]].size()){
                ans.push_back(mp[v[i]]);
                mp[v[i]]={};
            }
        }
        return ans;
    }
};
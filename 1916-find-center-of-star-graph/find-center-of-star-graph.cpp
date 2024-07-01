class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,int>mp;
        
        for(auto it:edges){
            mp[it[0]]++;if(mp[it[0]]==n)return it[0];
            mp[it[1]]++;if(mp[it[1]]==n)return it[1];
        }
        return -1;
    }
};
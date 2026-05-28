class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;

        for(int i=0;i<n;i++){
            string cur=strs[i];
            sort(cur.begin(),cur.end());
            mp[cur].push_back(strs[i]);
        }

        for(auto &c:mp) res.push_back(c.second);
        return res;
    }
};
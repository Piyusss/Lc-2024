class Solution {
public:

    string f(string &cur){
        string res="";
        vector<int>v(26,0);

        for(auto &c:cur) v[c-'a']++;
        for(int i=0;i<26;i++) if(v[i]!=0) res+=string(v[i],i+'a');

        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;

        for(int i=0;i<n;i++){
            string cur=strs[i];
            cur=f(cur);
            mp[cur].push_back(strs[i]);
        }

        for(auto &c:mp) res.push_back(c.second);
        return res;
    }
};
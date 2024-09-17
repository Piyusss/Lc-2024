class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        vector<string>res;
        string s=s1+" "+s2,token;
        unordered_map<string,int>mp;
        
        stringstream part(s);
        while(part >> token) mp[token]++;

        for(auto &it:mp)if(mp[it.first]==1) res.push_back(it.first);

        return res;

    }
};
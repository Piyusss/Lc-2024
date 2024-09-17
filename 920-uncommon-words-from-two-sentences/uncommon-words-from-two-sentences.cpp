class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        vector<string>res;
        string s=s1+" "+s2;
        unordered_map<string,int>mp;
        
        stringstream iss1(s);
        string token;
        while(iss1 >> token) mp[token]++;

        for(auto &it:mp){
            if(mp[it.first]==1) res.push_back(it.first);
        }

        return res;

    }
};
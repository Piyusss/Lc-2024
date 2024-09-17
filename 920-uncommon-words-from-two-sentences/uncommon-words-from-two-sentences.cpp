class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        vector<string>res;
        unordered_map<string,int>mp1,mp2;
        
        stringstream iss1(s1);
        string token1;
        while(iss1 >> token1) mp1[token1]++;

        stringstream iss2(s2);
        string token2;
        while(iss2 >> token2) mp2[token2]++;

        for(auto &it:mp1){
            if(mp1[it.first]==1 && mp2[it.first]==0)res.push_back(it.first);
        }
        for(auto &it:mp2){
            if(mp2[it.first]==1 && mp1[it.first]==0)res.push_back(it.first);
        }

        return res;

    }
};
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        vector<string>res,v1,v2;
        
        stringstream iss1(s1);
        string token1;
        while(iss1 >> token1) v1.push_back(token1);

        stringstream iss2(s2);
        string token2;
        while(iss2 >> token2) v2.push_back(token2);

        for(int i=0;i<v1.size();i++){
            if(count(v1.begin(),v1.end(),v1[i])==1 && find(v2.begin(),v2.end(),v1[i])==v2.end())res.push_back(v1[i]);
        }
        for(int i=0;i<v2.size();i++){
            if(count(v2.begin(),v2.end(),v2[i])==1 && find(v1.begin(),v1.end(),v2[i])==v1.end())res.push_back(v2[i]);
        }

        return res;

    }
};
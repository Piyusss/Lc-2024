class Solution {
public:
    bool isCircularSentence(string s){
        
        vector<string>v;
        stringstream ss(s);
        string token;
        while(ss>>token) v.push_back(token);

        int n=v.size();
        for(int i=0;i<n-1;i++) if(v[i].back()!=v[i+1].front()) return 0;

        return s[0] == s[s.size()-1] ? 1 : 0 ;

    }
};
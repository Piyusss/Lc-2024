class Solution {
public:
    bool isCircularSentence(string s){
        
        vector<string>v;
        stringstream ss(s);
        string token;
        while(ss>>token) v.push_back(token);

        int n=v.size();
        for(int i=0;i<n-1;i++) if(v[i][v[i].size()-1]!=v[i+1][0]) return 0;

        return v[0][0] == v[n-1][v[n-1].size()-1] ? 1 : 0 ;

    }
};
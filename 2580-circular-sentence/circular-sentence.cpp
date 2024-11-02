class Solution {
public:
    bool isCircularSentence(string s){

        vector<string>v;
        stringstream ss(s);
        string token;
        while(ss>>token) v.push_back(token);

        int n=v.size();
        if(n==1){
            if(v[0][0]==v[0][v[0].size()-1]) return 1;
            return 0;
        }

        for(int i=0;i<n-1;i++){
            string a=v[i];
            string b=v[i+1];
            if(a[a.size()-1]!=b[0]) return 0;
        }

        return v[0][0] == v[n-1][v[n-1].size()-1] ? 1 : 0 ;
        
    }
};
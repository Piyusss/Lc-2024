class Solution {
public:
    bool isCircularSentence(string s){
        vector<string>v;
    
        stringstream ss(s);
        string token;
        while(ss>>token) v.push_back(token);

        for(auto &it:v) cout<< it<< " ";

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

        string a=v[0];
        string b=v[n-1];

        return a[0] == b[b.size()-1] ? 1 : 0 ;
    }
};
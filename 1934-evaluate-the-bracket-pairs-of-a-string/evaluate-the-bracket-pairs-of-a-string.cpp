class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string>m;

        for(auto &x:k) m[x[0]]=x[1];
        string a;

        for(int i=0;i<s.size();i++){
            if(s[i]!='('){
                a+=s[i];
                continue;
            }

            int j=i+1;
            string x;

            while(s[j]!=')') x+=s[j++];

            if(m.count(x)) a+=m[x];
            else a+='?';

            i=j;
        }

        return a;
    }
};
class Solution {
public:
    string sortVowels(string s) {
        string res="";
        int n=s.size();

        vector<char>v;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                v.push_back(s[i]);
                s[i]='#';
            }
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                s[i]=v.back();
                v.pop_back();
            }
        }

        return s;
    }
};
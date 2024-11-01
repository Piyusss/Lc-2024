class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();

        string res="";
        for(int i=0;i<n-2;i++){
            if(!(s[i]==s[i+1] && s[i+1]==s[i+2])){
                res.push_back(s[i]);   
            }
        }
        
        if(n<=2) return s;
        return res + s[n-2] + s[n-1];

    }
};
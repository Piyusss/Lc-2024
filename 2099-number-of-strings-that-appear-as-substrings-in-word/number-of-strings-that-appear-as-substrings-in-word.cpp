class Solution {
public:
    int numOfStrings(vector<string>& a,string w) {
        int c=0;
        for(auto &s:a) if(w.find(s)!=string::npos) c++;
        return c;
    }
};
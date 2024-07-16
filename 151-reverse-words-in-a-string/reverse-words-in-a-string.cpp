class Solution {
public:
    string reverseWords(string s){

        reverse(s.begin(),s.end());
        
        stringstream ss(s);

        string res="";
        string token="";

        while(ss>>token){
            reverse(token.begin(),token.end());
            res+=token+" ";
        }

        res.pop_back();

        return res;
    }
}; 
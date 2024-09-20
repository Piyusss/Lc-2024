class Solution {
public:

    string shortestPalindrome(string s) {
        int n=s.size();

        string copy=s;
        reverse(copy.begin(),copy.end());

        for(int i=0;i<n;i++){
            if(memcmp(s.c_str(),copy.c_str()+i,n-i)==0) return copy.substr(0,i) + s;
        }
        
        return "";
    }
};
//aaacecaa
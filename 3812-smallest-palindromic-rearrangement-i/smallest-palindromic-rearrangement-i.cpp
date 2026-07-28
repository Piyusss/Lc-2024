class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        string t="";
        for(int i=0;i<(n&1?(n/2+1):n/2);i++) t+=s[i];
        sort(t.begin(),t.end()-(n&1));

        string final=t;
        for(int i=(n&1?(t.size()-2):(t.size()-1));i>=0;i--) final+=t[i];

        return final;
    }
};
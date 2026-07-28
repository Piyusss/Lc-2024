class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        string t="";
        for(int i=0;i<n/2;i++) t+=s[i];
        sort(t.begin(),t.end());

        string final=t;
        if(n&1) final+=s[n/2];
        for(int i=t.size()-1;i>=0;i--) final+=t[i];

        return final;
    }
};
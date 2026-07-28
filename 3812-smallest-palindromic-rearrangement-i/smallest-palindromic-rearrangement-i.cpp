class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        bool iseven=0;
        if(!(n&1)) iseven=1;

        bool isodd=(iseven==0)?1:0;

        string t="";

        for(int i=0;i<n/2;i++){
            t+=s[i];
        }

        sort(t.begin(),t.end());

        string final=t;
        if(isodd) final+=s[n/2];
        reverse(t.begin(),t.end());
        final+=t;

        return final;
    }
};
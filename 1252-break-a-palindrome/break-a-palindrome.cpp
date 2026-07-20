class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1) return "";

        int flag=0;

        for(int i=0;i<(n>>1) && !flag;i++){
            if(s[i] != 'a'){
                s[i]='a';
                flag=1;
            }
        }

        if(!flag) s[n-1]='b';
        return s;
    }
};
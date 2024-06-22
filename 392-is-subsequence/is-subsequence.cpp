class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        //now
        int move=0;int cnt=0;
        for(int i=0;i<n && move<m;i++){
            if(s[i]==t[move])cnt++;
            else i--;
            move++;
        }
        return (cnt==n);
    }
};
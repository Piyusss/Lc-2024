class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        for(int i=0;i<(n&1?((n>>1)+1):(n>>1));i++) s+=s[i];
        sort(s.begin()+n,s.end()-(n&1));
        cout<<s;

        int m=n&1?n+n/2+1:n+n/2;
        for(int i=(n&1?(m-2):(m-1));i>=n;i--) s+=s[i];

        return s.substr(n);
    }
};
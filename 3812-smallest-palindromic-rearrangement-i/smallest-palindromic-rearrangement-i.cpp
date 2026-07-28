class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        for(int i=0;i<(n&1?(n/2+1):n/2);i++) s+=s[i];
        s.erase(0,n);
        sort(s.begin(),s.end()-(n&1));
        cout<<s;

        int m=s.size();
        for(int i=(n&1?(m-2):(m-1));i>=0;i--) s+=s[i];
        
        return s;
    }
};
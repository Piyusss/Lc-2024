class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();

        for(int i=0;i<(n&1?((n>>1)+1):(n>>1));i++) s+=s[i];
        sort(s.begin()+n,s.end()-(n&1));

        for(int i=(n&1?((n&1?n+(n>>1)+1:n+(n>>1))-2):((n&1?n+(n>>1)+1:n+(n>>1))-1));i>=n;i--) s+=s[i];
        return s.substr(n);
    }
};

//so complex in look yet so beautiful :)
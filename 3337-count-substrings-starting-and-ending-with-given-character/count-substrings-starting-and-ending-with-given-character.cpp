class Solution {
public:
long long f(long long n){
    return n+n*(n-1)/2;
}
    long long countSubstrings(string s, char c) {
       int n=s.size();
       //now
       long long cnt=count(s.begin(),s.end(),c);
       return f(cnt);
    }
};
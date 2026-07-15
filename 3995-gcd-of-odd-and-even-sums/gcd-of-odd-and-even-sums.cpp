class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int so=1LL*n*n;
        int se=1LL*n*(n+1);
        return __gcd(so,se);
    }
};
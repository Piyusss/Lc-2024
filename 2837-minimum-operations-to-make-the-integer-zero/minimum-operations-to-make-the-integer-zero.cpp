class Solution {
public:

    using ll=long long;

    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
            ll x=(num1)-(1LL*num2*k);
            if(x<k) return -1;
            if(k>=__builtin_popcountll(x)) return k;
        }

        return -1;
    }
};
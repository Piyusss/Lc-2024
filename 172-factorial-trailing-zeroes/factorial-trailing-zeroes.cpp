class Solution {
public:

int f(int n){
    return n/5 + trailingZeroes(n/5);
}
    int trailingZeroes(int n){
        if(n<=4)return 0;

        return f(n);
    }
};

// 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100 105 110 115 120 125
// 25 50 75 100 125
// 125
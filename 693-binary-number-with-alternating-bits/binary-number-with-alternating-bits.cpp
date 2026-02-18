class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p=n&1;
        n>>=1;

        while(n){
            int c=n&1;
            if(c==p)return 0;

            p=c;
            n>>=1;
        }

        return 1;
    }
};
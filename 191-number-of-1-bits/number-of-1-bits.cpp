class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n){
            // n&=(n-1);
            // count++;

            count += (n%2);
            n>>=1;

            // count+= (n&1);
            // n>>=1;
        }
        return count;
    }
};
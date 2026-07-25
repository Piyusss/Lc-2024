class Solution {
public:
    int maxProduct(int n) {
        int m=0,sm=0;

        while(n){
            int d=n%10;

            if(d>m){
                sm=m;
                m=d;
            }
            else if(d>sm){
                sm=d;
            }

            n/=10;
        }

        return m*sm;
    }
};
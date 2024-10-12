class Solution {
public:

#define ll long long

    int divide(int dividend, int divisor){
        bool sign=1;
        if(dividend>0 ^ divisor>0) sign=0;

        if(dividend==divisor) return 1;

        ll n=abs(dividend);
        ll d=abs(divisor);

        ll res=0;

        while(n >= d){
            int cnt=0;
            while(n >= (d<<(cnt+1))) cnt++;

            res += 1<<cnt;
            n -= (d<<cnt);
        }

        if(res==(1<<31)) return sign ? INT_MAX : INT_MIN;

        return sign ? res : -res;
        
    }
};
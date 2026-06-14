class Solution {
public:

    int f(int idx,bool tight,string &s,int mask,bool lz){
        if(idx==s.size()) return 1;

        int lb=0,ub=tight?(s[idx]-'0'):9;

        int cnt=0;
        for(int dig=lb;dig<=ub;dig++){
            if(1 & (mask>>dig)) continue;
            cnt += f(idx+1,(tight&&dig==ub),s,(lz&&dig==0?0:(mask|(1<<dig))),(lz&&dig==0));
        }

        return cnt;
    }

    int countNumbersWithUniqueDigits(int n) {
        int r=(pow(10,n));
        r-=1;

        string s=to_string(r);

        return f(0,1,s,0,1);
    }
};
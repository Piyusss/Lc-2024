class Solution {
public:
    int totalMoney(int n) {
        int res=0,m=1,r=0;

        for(int i=1;i<=n;i++){
            if(!((i-1)%7)) r=m+1;
            res += ((i-1)%7==0 ? m : r)++;
        }

        return res;
    }
};
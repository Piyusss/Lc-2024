class Solution {
public:
    int totalMoney(int n) {
        //1 2 3 4 5 6 7 , 2 3 4 5 6 7 8 , 3 4 5 6 7

        int res=0,m=1,r=0;
        for(int i=1;i<=n;i++){
            if((i-1)%7==0){
                //this i is monday
                res += m;
                r=m+1;
                m++;
            }
            else{
                //this is tue-sun
                res += r;
                r++;
            }
        }

        return res;
    }
};
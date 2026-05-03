class Solution {
public:
    int rotatedDigits(int n) {
        int r=0;

        for(int x=1;x<=n;x++){
            int t=x;
            bool ok=1,chg=0;

            while(t){
                int d=t%10;
                if(d==3||d==4||d==7){
                    ok=0;
                    break;
                }

                if(d==2||d==5||d==6||d==9) chg=1;
                t/=10;
            }
            if(ok && chg) r+=1;
        }

        return r;
    }
};
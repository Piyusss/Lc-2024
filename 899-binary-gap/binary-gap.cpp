class Solution {
public:

    int binaryGap(int n) {
        int p=-1,i=0,r=0;

        while(n){
            if(n&1){
                if(p!=-1) r=max(r,i-p);
                p=i;
            }
            n>>=1;
            i++;
        }

        return r;
    }
};
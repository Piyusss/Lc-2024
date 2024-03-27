class Solution {
public:
    int minFlips(int a, int b, int c){
        int cnt=0;
        for(int i=0;i<32;i++){
            int lasta=a&1,lastb=b&1,lastc=c&1;

            if(lastc==0){
                if(lasta!=0 && lastb!=0)cnt+=2;
                else if(lasta==1 || lastb==1)cnt++;
            }
            else if(lasta==0 && lastb==0)cnt++;
            a>>=1;b>>=1;c>>=1;
        }
        return cnt;
    }
};
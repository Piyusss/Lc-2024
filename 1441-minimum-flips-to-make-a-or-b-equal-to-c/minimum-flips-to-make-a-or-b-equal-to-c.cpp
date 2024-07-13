class Solution {
public:
    int minFlips(int a, int b, int c){
        int cnt=0;
        for(int i=0;i<32;i++){
            int lasta=a&1,lastb=b&1,lastc=c&1;

            if(!lastc){
                if(lasta && lastb)cnt+=2;
                else if(lasta || lastb)cnt++;
            }
            else if(!lasta && !lastb)cnt++;
            a>>=1;b>>=1;c>>=1;
        }
        return cnt;
    }
};
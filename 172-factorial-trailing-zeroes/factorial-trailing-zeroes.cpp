class Solution {
public:

int NoOfFivesInprimeFactoriz(int n) {
    int cnt=0;

    for(int i=3;i*i<=n;i+=2) {
        while(n%i == 0) {
            if(i%5==0) cnt++;
            n/=i;
        }
    }
    if(n>2 && n%5==0) cnt++;
    return cnt;
}

    int trailingZeroes(int n) {
        if(n<=4) return 0;

        int cnt=0;

        for(int i=1;i<=n;i++){
            if(i%5==0){
                cnt+= NoOfFivesInprimeFactoriz(i);
            }
        }

        return cnt;
    }
};
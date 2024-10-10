class Solution {
public:

int NoOfFivesInprimeFactoriz(int n){
    int cnt=0;

    for(int i=3;i*i<=n;i+=2){
        while(n%i == 0){
            if(i%5==0) cnt++;
            n/=i;
        }
    }

    return cnt + (n%5==0 ? 1 : 0);
}

    int trailingZeroes(int n){
        if(n<=4) return 0;

        int cnt=0;

        for(int i=5;i<=n;i++){
            if(i%5==0){
                cnt+= NoOfFivesInprimeFactoriz(i);
            }
        }

        return cnt;
    }
};
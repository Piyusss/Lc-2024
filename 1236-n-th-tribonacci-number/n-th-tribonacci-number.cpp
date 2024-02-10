class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        int sslast=0;
        int secondLast = 1;
        int last = 1;
        int curr = 2;
        
        n = n-2;
        while(n>0){
            curr = (last + secondLast + sslast);
            sslast = secondLast;
            secondLast = last;
            last=curr;
            n--;
        }
        return curr;
    }
};
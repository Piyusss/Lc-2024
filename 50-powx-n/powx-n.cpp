class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long temp=n;
        if(temp<0)temp=-1*temp;
        while(temp){
            if(temp%2){
                ans*=x;
                temp--;
            }
            else{
                x*=x;
                temp/=2;
            }
        }
        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=-1;

        if(n==1){
            return true;
        }
        if(n==0){
            return false;
        }

        while(n!=1){
        if(n%2==0){
            n=n/2;
            ans=1;
        }
        else{
            ans=0;
            break;
        }
     }

     if(ans==1){
         return true;
     }
     else{
         return false;
     }
    }
};
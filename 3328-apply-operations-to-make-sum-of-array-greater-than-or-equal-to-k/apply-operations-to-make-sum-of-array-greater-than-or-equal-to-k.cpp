class Solution {
public:
    int minOperations(int k){
        if(k==1)return 0;
        int t=k;
        //now
        int flag=1;int mini=INT_MAX;
        for(int i=1;i<=t;i++){
            int add1=i-1;
            int add2=t/i;
            if(t%i==0)add2--;
            mini=min(mini,add1+add2);
        }
        return mini;
    }
};
//t is even
    //per  div- add2--;
    //else add2 only
//t is odd
    //not per div add2 only;
    //else add2--;
//15->6
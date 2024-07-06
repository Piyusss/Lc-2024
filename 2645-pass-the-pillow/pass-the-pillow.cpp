class Solution {
public:
    int passThePillow(int n, int time){
        int ind=0;
        int flag=1;
        while(time--){
            if(ind==n-1)flag=0;
            if(ind==0)flag=1;

            if(flag)ind++;
            else ind--;

        }
        return ind+1;
    }
};
// 1 2 3 4
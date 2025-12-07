class Solution {
public:
    int countOdds(int l, int h) {
        return (++h>>1)-(l>>1);

        //or
        // return (++h/2)-(l/2);
        //or
        // return (h+1)/2-(l)/2;
        //or
        // return (h+1)/2-(--l+1)/2;
        //or
        // return ((h+1)/2)-((--l+1)/2);
        
        //or
        // l--;
        // int leftEnd=(l+1)/2;
        // int rightEnd=(h+1)/2;
        // return rightEnd-leftEnd;

        //or
        // int cnt=0;
        // for(int i=low;i<=high;i++) if(i&1) cnt++;
        // return cnt;
    }
};

// 3 and 7 - odd and odd - 3 5 7 - 3 - (7/2)-(2/2)=4-1=3
// 8 and 10 - even and even - 9 - 1 - (10/2)-(7/2)=5-4=1
// 2 and 7 - even and odd - 3 5 7 - (7/2)-(1/2)=4-1=3
// 3 and 12 - odd and even - 3 5 7 9 11 - 5 - (12/2)-(2/2)=6-1=5
// 0 and 10 - 1 3 5 7 9 - 5 - (10/2)-(-1/2)=5-0=5
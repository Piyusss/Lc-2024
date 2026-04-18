class Solution {
public:
    int mirrorDistance(int n) {
        int r=0,t=n;

        while(t) r=r*10+(t%10),t/=10;
        return abs(n-r);
    }
};
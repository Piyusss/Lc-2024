class Solution {
public:
    bool checkOverlap(int r, int x, int y, int a, int b, int c, int d) {
        int p=max(a,min(x,c))-x;
        int q=max(b,min(y,d))-y;
        
        return p*p+q*q<=r*r;
    }
};
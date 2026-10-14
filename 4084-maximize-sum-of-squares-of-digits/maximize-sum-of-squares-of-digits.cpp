class Solution {
public:
    string maxSumOfSquares(int n, int s) {
        if(s>9*n) return "";

        string a;
        int x=s/9;
        s%=9;

        a.append(x,'9');
        if(s) a+=char('0'+s);

        a.append(n-a.size(),'0');
        return a;
    }
};
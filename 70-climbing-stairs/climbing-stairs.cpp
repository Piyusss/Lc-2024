class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        int prev=2,prevprev=1;

        for(int i=3;i<=n;i++){
            int cur=prevprev+prev;
            prevprev=prev;
            prev=cur;
        }

        return prev;
    }
};
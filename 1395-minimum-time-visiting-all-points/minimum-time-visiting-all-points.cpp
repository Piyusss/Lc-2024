class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int res=0;
        
        for(int i=0;i<p.size()-1;i++){
            int curX=p[i][0], curY=p[i][1];
            int nextX=p[i+1][0], nextY=p[i+1][1];
        
            int dx=abs(nextX-curX), dy=abs(nextY-curY);
            res += max(dx,dy);
        }
        
        return res;
    }
};
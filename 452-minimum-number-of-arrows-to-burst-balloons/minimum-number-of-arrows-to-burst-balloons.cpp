class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int>prev=points[0];
        int cnt=1;

        for(int i=1;i<n;i++){
            int curStartPoint=points[i][0];
            int curEndPoint=points[i][1];

            int prevStartPoint=prev[0];
            int prevEndPoint=prev[1];

            if(curStartPoint>prevEndPoint){
                cnt++;
                prev=points[i];
            }
            else{
                prev[0]=max(curStartPoint,prevStartPoint);
                prev[1]=min(curEndPoint,prevEndPoint);
            }
        }
        return cnt;
    }
};
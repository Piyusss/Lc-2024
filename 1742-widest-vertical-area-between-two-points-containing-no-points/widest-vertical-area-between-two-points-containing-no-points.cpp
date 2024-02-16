class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points){
        int n=points.size();
        sort(points.begin(),points.end());
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,points[i+1][0]-points[i][0]);
        }
        return maxi;
    }
};
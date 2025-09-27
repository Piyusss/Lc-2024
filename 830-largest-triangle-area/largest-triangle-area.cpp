class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n=p.size();
        double ans=0;

        for(int i=0;i<n-2;i++){
            int ax=p[i][0],ay=p[i][1];

            for(int j=i+1;j<n-1;j++){
                int bx=p[j][0],by=p[j][1];

                for(int k=j+1;k<n;k++){
                    int cx=p[k][0],cy=p[k][1];
                    double ar=0.5*abs((bx-ax)*(cy-ay)-(cx-ax)*(by-ay));

                    if(ar>ans)ans=ar;
                }
            }
        }
        
        return ans;
    }
};
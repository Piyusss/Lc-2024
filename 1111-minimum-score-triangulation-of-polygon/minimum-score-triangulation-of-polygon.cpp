class Solution {
public:
    int minScoreTriangulation(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>d(n,vector<int>(n,0));

        for(int len=2;len<n;len++){
            for(int i=0;i+len<n;i++){

                int j=i+len;
                d[i][j]=INT_MAX;

                for(int k=i+1;k<j;k++){
                    int cur=d[i][k]+d[k][j]+a[i]*a[j]*a[k];
                    if(cur<d[i][j])d[i][j]=cur;
                }

            }
        }

        return d[0][n-1];
    }
};
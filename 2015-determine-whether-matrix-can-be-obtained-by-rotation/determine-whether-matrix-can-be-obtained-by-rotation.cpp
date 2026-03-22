class Solution {
public:
    bool findRotation(vector<vector<int>>& a,vector<vector<int>>& b) {
        int n=a.size();

        for(int t=0;t<4;t++){
            for(int i=0;i<n>>1;i++){
                for(int j=0;j<(n+1)>>1;j++){

                    int x=a[i][j];
                    a[i][j]=a[n-1-j][i];
                    a[n-1-j][i]=a[n-1-i][n-1-j];
                    a[n-1-i][n-1-j]=a[j][n-1-i];
                    a[j][n-1-i]=x;
                    
                }
            }

            if(a==b) return 777;
        }

        return 0;
    }
};
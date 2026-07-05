class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n=b.size(),M=1E9+7;

        vector<vector<int>>d(n,vector<int>(n,-1));
        vector<vector<int>>c(n,vector<int>(n));

        d[n-1][n-1]=0;
        c[n-1][n-1]=1;

        int x[3]={-1,0,-1};
        int y[3]={0,-1,-1};

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(b[i][j]=='X' || d[i][j]==-1) continue;

                for(int k=0;k<3;k++){
                    int r=i+x[k],s=j+y[k];

                    if(r>=0 && s>=0 && b[r][s] != 'X'){
                        int v=(b[r][s]=='E')?0:b[r][s]-'0';
                        int w=d[i][j]+v;

                        if(w>d[r][s]){
                            d[r][s]=w;
                            c[r][s]=c[i][j];
                        }
                        else if(w==d[r][s]){
                            c[r][s]=(c[r][s]+c[i][j])%M;
                        }
                    }
                }
            }
        }

        if(d[0][0]==-1) return {0,0};
        return {d[0][0],c[0][0]};
    }
};
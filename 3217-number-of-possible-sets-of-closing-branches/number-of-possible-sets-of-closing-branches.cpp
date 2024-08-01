class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int cnt=0;

        for(int sel_banks=0;sel_banks<=(1<<n)-1;sel_banks++){
            vector<vector<int>>adjMat(n,vector<int>(n,1e9));
            for(int j=0;j<n;j++)adjMat[j][j]=0;

            for(auto &it:roads){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if( 1&(sel_banks>>u) && 1&(sel_banks>>v)){
                    adjMat[u][v]=min(adjMat[u][v],w);
                    adjMat[v][u]=min(adjMat[v][u],w);
                }

            }


            for(int via=0;via<n;via++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        adjMat[i][j]=min(adjMat[i][j],adjMat[i][via]+adjMat[via][j]);
                    }
                }
            }

            int mark=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(1&(sel_banks>>i) && 1&(sel_banks>>j) && adjMat[i][j]>maxDistance){
                        mark=1;
                        break;
                    }
                }
            }
            if(mark==0)cnt++;

        }
        return cnt;
    }
};
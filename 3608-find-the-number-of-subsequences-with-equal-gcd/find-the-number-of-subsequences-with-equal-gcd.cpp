class Solution {
public:

    static constexpr int N=200;
    static constexpr int M=1E9+7;

    int subsequencePairCount(vector<int>& a) {
        static int d[N+1][N+1];
        static int nd[N+1][N+1];

        memset(d,0,sizeof(d));
        d[0][0]=1;

        for(auto &x:a){
            memset(nd,0,sizeof(nd));

            for(int i=0;i<=N;i++){
                for(int j=0;j<=N;j++){
                    if(!d[i][j]) continue;

                    nd[i][j]=(nd[i][j]+d[i][j])%M;

                    int u=i?gcd(i,x):x;
                    nd[u][j]=(nd[u][j]+d[i][j])%M;

                    int v=j?gcd(j,x):x;
                    nd[i][v]=(nd[i][v]+d[i][j])%M;
                }
            }

            memcpy(d,nd,sizeof(d));
        }

        long long ans=0;

        for(int i=1;i<=N;i++){
            ans=(ans+d[i][i])%M;
        }

        return ans;
    }
};
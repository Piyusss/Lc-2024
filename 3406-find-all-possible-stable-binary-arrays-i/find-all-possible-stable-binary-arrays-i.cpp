using ll=long long;
const int M=1E9+7;

class Solution {
public:
    int numberOfStableArrays(int z,int o,int l) {
        vector<vector<vector<ll>>>d(z+1,vector<vector<ll>>(o+1,vector<ll>(2)));
        d[0][0][0]=d[0][0][1]=1;

        for(int i=0;i<=z;i++){
            for(int j=0;j<=o;j++){
                for(int k=1;k<=l;k++){

                    if(i>=k) d[i][j][0]=(d[i][j][0]+d[i-k][j][1]) % M;
                    if(j>=k) d[i][j][1]=(d[i][j][1]+d[i][j-k][0]) % M;

                }
            }
        }

        return (d[z][o][0]+d[z][o][1]) % M;
    }
};
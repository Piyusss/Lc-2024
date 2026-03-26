using ll=long long;
const int M=100001;
static int a[M];
static bitset<M>b;

class Solution {
public:
    static bool canPartitionGrid(vector<vector<int>>& g) {
        int r=g.size(),c=g[0].size(),N=r*c;
        ll S=0;

        b.reset();
        int id=0;

        for(auto &x:g){
            memcpy(a+id,x.data(),sizeof(int)*c);
            id+=c;
        }

        int mx=0;
        for(int i=0;i<N;i++){
            S+=a[i];
            mx=max(mx,a[i]);
        }

        ll t=0;
        for(int i=0;i<r-1;i++){
            for(int j=0;j<c;j++){
                int x=a[i*c+j];
                t+=x;
                b[x]=1;
            }

            ll d=t-(S-t);
            if(!d) return 1;

            if(d>0&&d<=mx){
                if(i>0&&c>1){
                    if(b[d]) return 1;
                }
                else{
                    if(a[0]==d||a[(i+1)*c-1]==d) return 1;
                }
            }
        }

        b.reset();
        ll bt=0;

        for(int i=r-1;i>=1;i--){
            for(int j=c-1;j>=0;j--){
                int x=a[i*c+j];
                bt+=x;
                b[x]=1;
            }

            ll d=bt-(S-bt);
            if(d>0&&d<=mx){
                if((r-1-i)>0&&c>1){
                    if(b[d]) return 1;
                }
                else{
                    if(a[i*c]==d||a[N-1]==d) return 1;
                }
            }
        }

        b.reset();
        ll L=0;

        for(int j=0;j<c-1;j++){
            for(int i=0;i<r;i++){
                int x=a[i*c+j];
                L+=x;
                b[x]=1;
            }

            ll d=L-(S-L);
            if(!d) return 1;

            if(d>0&&d<=mx){
                if(r>1&&j>0){
                    if(b[d]) return 1;
                }
                else{
                    if(a[0]==d||a[(r-1)*c+j]==d) return 1;
                }
            }
        }

        b.reset();
        ll R=0;

        for(int j=c-1;j>=1;j--){
            for(int i=0;i<r;i++){
                int x=a[i*c+j];
                R+=x;
                b[x]=1;
            }

            ll d=R-(S-R);
            if(d>0&&d<=mx){
                if(r>1&&(c-1-j)>0){
                    if(b[d]) return 1;
                }
                else{
                    if(a[j]==d||a[N-1]==d) return 1;
                }
            }
        }

        return 0;
    }
};
class Solution {
public:
    int minMoves(vector<int>& a,int l) {
        int n=a.size();
        static int d[200002];
        memset(d,0,sizeof(d));

        d[0]=n;
        int mx=0;

        for(int i=0;i<n/2;i++){
            int x=a[i],y=a[n-i-1];

            mx=max(mx,x+y);

            d[x+y]--;
            d[x+y+1]++;

            d[min(x,y)+1]--;
            d[max(x,y)+l+1]++;
        }

        int res=INT_MAX,c=0;

        for(int i=0;i<=mx;i++){
            c+=d[i];
            res=min(res,c);
        }

        return res;
    }
};
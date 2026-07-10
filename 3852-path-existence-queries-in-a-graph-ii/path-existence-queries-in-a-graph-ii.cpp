static constexpr int L=19;

class Solution {
public:

    vector<int> pathExistenceQueries(int n,vector<int>& a,int d,vector<vector<int>>& q) {
        vector<int>ans;
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++) v.push_back({a[i],i});
        sort(v.begin(),v.end());

        vector<array<int,L>>up(n);

        int r=n-1;

        for(int l=n-1;l>=0;l--){
            while(v[r].first-v[l].first>d) r--;

            int x=v[l].second;
            up[x][0]=v[r].second;

            for(int i=1;i<L;i++) up[x][i]=up[up[x][i-1]][i-1];
        }

        for(auto &x:q){
            int u=x[0],v=x[1];

            if(a[u]>a[v]) swap(u,v);

            if(u==v){
                ans.push_back(0);
                continue;
            }

            int t=a[v],s=0;

            for(int i=L-1;i>=0;i--){
                int y=up[u][i];

                if(a[y]<t){
                    u=y;
                    s+=1<<i;
                }
            }

            if(a[up[u][0]]<t) ans.push_back(-1);
            else ans.push_back(s+1);
        }

        return ans;
    }
};
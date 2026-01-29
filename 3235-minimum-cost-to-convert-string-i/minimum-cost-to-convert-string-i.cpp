class Solution {
public:

    using ll=long long;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        vector<vector<ll>>dist(n,vector<ll>(n,INT_MAX));
        
        for(int i=0;i<n;i++)dist[i][i]=0;
        
        for(int i=0;i<original.size();i++){
            
            int src=original[i]-'a';
            int dst=changed[i]-'a';
            ll wt=cost[i];
            
            dist[src][dst]=min(dist[src][dst] , wt);
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
            
        ll res=0;
        for(int i=0;i<source.length();i++){
            int src=source[i]-'a';
            int dest=target[i]-'a';

            if(src==dest) continue;

            if(dist[src][dest]==INT_MAX ) return -1;
            else res += (ll)dist[src][dest];
        }

        return res;
    }
};
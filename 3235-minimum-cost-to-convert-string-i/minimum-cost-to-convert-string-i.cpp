class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        vector<vector<long long>>dist(n,vector<long long>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        
        for(int i=0;i<original.size();i++){
            
            int src=original[i]-'a';
            int dst=changed[i]-'a';
            long long wt=cost[i];
            
            dist[src][dst]=min(dist[src][dst] , wt);
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
            
            long long result = 0;
            for(int i=0; i<source.length();i++){
                    int src = source[i]-'a';
                    int dest = target[i]-'a';
                    if(src == dest) continue;
                    if(dist[src][dest] == INT_MAX ) return -1;
                    else result += (long long)dist[src][dest];
            }
            
            return result;
    }
};
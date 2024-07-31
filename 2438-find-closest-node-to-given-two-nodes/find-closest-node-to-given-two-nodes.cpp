class Solution {
public:

void dijsktra(vector<int>adjList[],vector<int>& dis,int node,int flag,vector<int> &vis){
    vis[node]=1;
    dis[node]=flag;

    for(auto &it:adjList[node]){
        if(!vis[it]){
            dijsktra(adjList,dis,it,flag+1,vis);
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();

        vector<int>adjList[n];

        for(int i=0;i<n;i++){
            int u=i;
            int v=edges[i];

            if(u!=-1 && v!=-1){
                adjList[u].push_back(v);
            }
        }

        vector<int>dis1(n,1e9);dis1[node1]=0;
        vector<int>dis2(n,1e9);dis2[node2]=0;

        vector<int>visited(n,0);
        dijsktra(adjList,dis1,node1,0,visited);
        vector<int>visited2(n,0);
        dijsktra(adjList,dis2,node2,0,visited2);

        vector<pair<int,int>>v;

        for(auto it:dis1)cout<<it<<" ";
        cout<<endl;
        for(auto it:dis2)cout<<it<<" ";
        
        int mark=0;
        for(int i=0;i<n;i++){
            if(dis1[i]!=1e9 && dis2[i]!=1e9){
                v.push_back({max(dis1[i],dis2[i]),i});
                mark=1;
            }
        }

        if(mark==0)return -1;
        sort(v.begin(),v.end());

        return v[0].second;
    }
};
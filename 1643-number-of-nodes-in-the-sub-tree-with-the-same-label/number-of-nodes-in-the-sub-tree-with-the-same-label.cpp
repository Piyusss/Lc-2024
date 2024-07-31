class Solution {
public:

vector<int> dfs(int cur,int par,vector<int> adjList[],string &labels,vector<int>& result){
    vector<int>temp(26);
    temp[labels[cur]-'a']=1;

    for(auto &it:adjList[cur]){
        if(it==par)continue;
        vector<int>child(26);
        child=dfs(it,cur,adjList,labels,result);
        for(int i=0;i<26;i++)temp[i]+=child[i];
    }
    result[cur]=temp[labels[cur]-'a'];
    return temp;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adjList[n];

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>result(n);
        vector<int> ans=dfs(0,-1,adjList,labels,result);
        return result;

    }
};
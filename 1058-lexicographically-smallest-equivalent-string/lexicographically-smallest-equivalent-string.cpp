class Solution {
public:

void dfs(int node,vector<int> adjList[],vector<char>&v,vector<int>& vis){
    vis[node]=1;
    v.push_back(node+'a');

    for(auto &it:adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,v,vis);
        }
    }
}
    string smallestEquivalentString(string s1, string s2, string baseStr){
        int n=s1.size();

        vector<int>adjList[26+1];
        string ans="";


        for(int i=0;i<n;i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';

            if(u!=v){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        for(int i=0;i<baseStr.size();i++){
            vector<char>v;
            vector<int>vis(26,0);
            dfs(baseStr[i]-'a',adjList,v,vis);
            sort(v.begin(),v.end());
            ans+=v[0];
        }
        return ans;
    }
};
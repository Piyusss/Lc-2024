class Solution {
public:

void dfs(int node,vector<char>&chars,vector<int>&indices,vector<int>adjList[],vector<int>& vis,string &s){
    vis[node]=1;
    chars.push_back(s[node]);
    indices.push_back(node);

    for(auto it:adjList[node]){
        if(!vis[it]){
            dfs(it,chars,indices,adjList,vis,s);
        }
    }
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int>adjList[n];

        for(auto it:pairs){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>vis(n);
        string ans="";
        for(int i=0;i<n;i++)ans+=" ";

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>indices;
                vector<char>chars;
                dfs(i,chars,indices,adjList,vis,s);
                sort(indices.begin(),indices.end());
                sort(chars.begin(),chars.end());

                for(int i=0;i<indices.size();i++)ans[indices[i]]=chars[i];
            }
        }

        return ans;
    }
};
class Solution {
public:

unordered_map<string,priority_queue<string,vector<string>,greater<string> >>adj;
vector<string>ans;

void dfs(string node){
    auto &adjNodes=adj[node];
    
    while(!adjNodes.empty()){
        auto v=adjNodes.top();
        adjNodes.pop();
        dfs(v);
    }

    ans.push_back(node);
}
    vector<string> findItinerary(vector<vector<string>>& tickets){
        for(auto &it:tickets) adj[it[0]].push(it[1]);

        dfs("JFK");

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
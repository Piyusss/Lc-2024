class Solution {
public:

void dfs(string src,string &dest,unordered_map<string,vector<pair<string,double>>> &adjList,unordered_set<string>& vis,double &ans, double product,int &mark){
    vis.insert(src);

    if(src==dest){
        ans=product;
        mark=1;
        return;
    }

    for(auto it:adjList[src]){
        string it2=it.first;
        double path_len=it.second;
        if(vis.count(it2)==0){
            dfs(it2,dest,adjList,vis,ans,product*path_len,mark);
        }
    }
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // vector<pair<string,double>>adjList[];

        unordered_map<string,vector<pair<string,double>>>adjList;

        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double w=values[i];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,1.0/w});

        }

        vector<double>ans(queries.size(),-1.0);

        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dest=queries[i][1];

            if(adjList[src].size()>0 && adjList[dest].size()>0){
                double flag=1.0;
                double product=1.0;
                int mark=0;
                unordered_set<string>vis;
                dfs(src,dest,adjList,vis,flag,product,mark);
                if(mark==1) ans[i]=flag;
            }
        }

        return ans;
        
    }
};
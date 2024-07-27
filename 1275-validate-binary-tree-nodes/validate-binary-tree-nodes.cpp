class Solution {
public:

void dfs(int node,vector<int>adjList[],vector<int>& vis,vector<int>& cnt){
    vis[node]=1;
    cnt[0]++;

    for(auto &it:adjList[node]){
        if(!vis[it])dfs(it,adjList,vis,cnt);
    }
}
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){

        vector<int>adjList[n+1];
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int left_Child=leftChild[i];
            int right_Child=rightChild[i];

            if(left_Child!=-1){
                adjList[i].push_back(left_Child);
                if(mp.find(left_Child)!=mp.end())return 0;
                mp[left_Child]=i;
            }
            if(right_Child!=-1){
                adjList[i].push_back(right_Child);
                if(mp.find(right_Child)!=mp.end())return 0;
                mp[right_Child]=i;
            }
        }

        int noOfRoots=0;
        int root=-1;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                noOfRoots++;
                root=i;
            }
        }
        if(noOfRoots>1)return 0;
        if(root==-1)return 0;

        vector<int>cnt(1,0);
        vector<int>vis(n,0);
        dfs(root,adjList,vis,cnt);

        return cnt[0]==n;
    }
};
class Solution {
public:


int n;
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};


bool checkIfThisMidValueIsAllowedOnAnyPathFromStartToEnd(int mid,vector<vector<int>>&distMatrix){
    queue<pair<int,int>>q;
    q.push({0,0});

    vector<vector<bool>> vis(n,vector<bool>(n,0));
    vis[0][0]=1;

    if(distMatrix[0][0]<mid)return 0;

    
    while(!q.empty()){
        int cur_i=q.front().first;
        int cur_j=q.front().second;
        q.pop();

        if(cur_i==n-1 && cur_j==n-1)return 1;

        for(auto &it:dir){
            int new_i=cur_i+it[0];
            int new_j=cur_j+it[1];
            if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && !vis[new_i][new_j]){
                if(distMatrix[new_i][new_j]<mid)continue;
                q.push({new_i,new_j});
                vis[new_i][new_j]=1;
            }
        }
    }


    return 0;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();

        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        vector<vector<int>>distMatrix(n,vector<int>(n,-1));
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int cur_i=q.front().first;
                int cur_j=q.front().second;
                q.pop();

                distMatrix[cur_i][cur_j]=level;

                for(auto &it:dir){
                    int new_i=cur_i+it[0];
                    int new_j=cur_j+it[1];
                    if(new_i<0 || new_j<0 || new_i>=n || new_j>=n || vis[new_i][new_j])continue;
                    q.push({new_i,new_j});
                    vis[new_i][new_j]=1;
                }
            }
            level++;
        }


        int left=0;
        int right=400;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(checkIfThisMidValueIsAllowedOnAnyPathFromStartToEnd(mid,distMatrix)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }

        return ans;
    }
};
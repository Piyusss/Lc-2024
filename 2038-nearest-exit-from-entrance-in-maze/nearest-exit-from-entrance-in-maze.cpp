class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //shortest-path-matlab-bfs
        int n=maze.size();
        int m=maze[0].size();

        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int cnt=0;

        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        while(!q.empty()){
            int nn=q.size();
            while(nn--){
                pair<int,int>temp=q.front();
                int i=temp.first;
                int j=temp.second;
                if((i==0 || i==n-1 || j==0 || j==m-1)
                && (temp!=make_pair(entrance[0],entrance[1]))){
                    return cnt;
                }
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr>=0 && nr<=n-1 && nc>=0 && nc<=m-1 && maze[nr][nc]!='+'){
                        maze[nr][nc]='+';
                        q.push({nr,nc});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
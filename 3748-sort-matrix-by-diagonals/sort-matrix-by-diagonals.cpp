class Solution {
    void f3(vector<vector<int>>& grid, unordered_map<int, vector<int>>& d){
        int n=grid.size();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i-j].push_back(grid[i][j]);
    }

    void f2(unordered_map<int, vector<int>>& d){
        for(auto &e:d) e.first>=0?sort(e.second.rbegin(),e.second.rend()):sort(e.second.begin(),e.second.end());
    }

    void f1(vector<vector<int>>& grid, unordered_map<int, vector<int>>& d){
        int n=grid.size();
        unordered_map<int,int> p;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) grid[i][j]=d[i-j][p[i-j]++];
    }

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid){
        unordered_map<int,vector<int>>d;

        f3(grid,d);
        f2(d);
        f1(grid,d);

        return grid;
    }
};
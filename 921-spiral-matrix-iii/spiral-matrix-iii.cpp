class Solution {
public:

vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {
        int d=0,step=0;
        int totalCells=n*m;

        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});

        while(ans.size()<totalCells){
            if(d==0 || d==2)step++;
            for(int i=0;i<step;i++){
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && rStart<n && cStart>=0 && cStart<m)ans.push_back({rStart,cStart});
            }
            d++;
            if(d>3)d=0;
        }

        return ans;
    }
};
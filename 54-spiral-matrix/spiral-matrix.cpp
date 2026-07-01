class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<int>ans;
        int left=0,top=0,bottom=n-1,right=m-1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++) ans.push_back(grid[top][i]);
            top+=1;
            
            for(int i=top;i<=bottom;i++) ans.push_back(grid[i][right]);
            right-=1;

            if(top<=bottom){
                for(int i=right;i>=left;i--) ans.push_back(grid[bottom][i]);
                bottom-=1;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--) ans.push_back(grid[i][left]);
                left+=1;
            }
        }
        
        return ans;
    }
};
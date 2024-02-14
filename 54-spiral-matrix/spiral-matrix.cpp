class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int left=0,top=0,bottom=n-1,right=m-1;
        vector<int>ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(grid[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(grid[i][right]);
            }
            right--;

            //now

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(grid[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(grid[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
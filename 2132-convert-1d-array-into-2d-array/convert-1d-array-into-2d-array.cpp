class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n){
        vector<vector<int>>ans;
        if(original.size()!=m*n)return ans;

        int k=0;

        ans.resize(m);
        for(auto &row:ans)row.resize(n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[k++];
            }
        }

        return ans;
        
    }
};
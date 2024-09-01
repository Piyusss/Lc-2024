class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n){
        vector<vector<int>>ans;
        if(original.size()!=m*n)return ans;

        int k=0;

        vector<vector<int>>ans2(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans2[i][j]=original[k];
                k++;
            }
        }

        return ans2;
        
    }
};
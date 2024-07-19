class Solution {
public:

bool lucky(vector<vector<int>>& matrix,int i,int j,int n,int m){
    int val=matrix[i][j];
    int mini=INT_MAX;
    for(int col=0;col<m;col++){
        mini=min(mini,matrix[i][col]);
    }
    int maxi=INT_MIN;
    for(int row=0;row<n;row++){
        maxi=max(maxi,matrix[row][j]);
    }

    if(mini==val && maxi==val)return 1;
    return 0;
}
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(lucky(matrix,i,j,n,m))ans.push_back(matrix[i][j]);
            }
        }

        return ans;
    }
};
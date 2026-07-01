class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();

        int i=0,j=m-1;

        while(i<=n-1 && j>=0){
            if(target>matrix[i][j]) i+=1;
            else if(target<matrix[i][j]) j-=1;
            else return 1;
        }

        return 0;
    }
};
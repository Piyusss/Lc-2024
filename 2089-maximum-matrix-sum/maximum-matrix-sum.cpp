using ll=long long;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        ll tot=0;
        int mini=INT_MAX;
        ll cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0) cnt++;

                tot += abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }

        if(cnt&1) return tot-(2*mini);
        return tot;
    }
};
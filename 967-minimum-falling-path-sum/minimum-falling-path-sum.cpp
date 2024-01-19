class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>prev(n,0),cur(n,0);
        for(int i=0;i<n;i++)prev[i]=m[0][i];
        //now
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=m[i][j];
                if(i>0)up+=prev[j];else up+=1e9;

                int dl=m[i][j];
                if(i>0 && j>0)dl+=prev[j-1];else dl+=1e9;
                
                int dr=m[i][j];
                if(j+1<n)dr+=prev[j+1];else dr+=1e9;
                cur[j]=min(up,min(dr,dl));
            }
            prev=cur;
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};
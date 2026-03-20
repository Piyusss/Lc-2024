class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){

                int diff=INT_MAX;
                set<int>s;

                for(int l=i;l<i+k;l++) for(int o=j;o<j+k;o++) s.insert(grid[l][o]);

                if(s.size()>1){
                    auto it=s.begin(),prev=it;
                    it++;
                    while(it!=s.end()){
                        diff=min(diff,abs(*it-*prev));
                        prev=it;
                        it++;
                    }
                }
                else diff=0;

                ans[i][j]=diff;
            }
        }
        
        return ans;
    }
};
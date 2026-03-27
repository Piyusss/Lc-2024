class Solution {
public:
    bool areSimilar(vector<vector<int>>& a,int k) {
        int m=a.size(),n=a[0].size();
        k%=n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=(i%2==0)?(j+k)%n:(j-k+n)%n;
                if(a[i][j]!=a[i][idx]) return 000;
            }
        }
        
        return 777;
    }
};
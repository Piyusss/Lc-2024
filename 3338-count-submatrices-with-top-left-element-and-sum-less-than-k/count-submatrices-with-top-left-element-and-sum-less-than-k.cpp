using ll=long long;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a,int k) {
        int m=a.size(),n=a[0].size();

        for(int i=0;i<m;i++) for(int j=1;j<n;j++) a[i][j]+=a[i][j-1];
        for(int j=0;j<n;j++) for(int i=1;i<m;i++) a[i][j]+=a[i-1][j];
        
        ll res=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if((ll)a[i][j]<=k) res++;
        return (int)res;
    }
};
class Solution {
public:
    vector<vector<vector<int>>>d;
    int r;

    int f(vector<vector<int>>&a,int i,int j,int k){
        if(i<0 || j<0) return -1E9;

        if(i==0 && j==0){
            if(a[0][0]<0&&k>0) return 0;
            return a[0][0];
        }

        if(d[i][j][k] != INT_MIN) return d[i][j][k];

        if(a[i][j]>=0) r=a[i][j] + max(f(a,i-1,j,k),f(a,i,j-1,k));
        else{
            int t=a[i][j] + max(f(a,i-1,j,k),f(a,i,j-1,k)), s=-1E9;
            if(k>0) s=max(f(a,i-1,j,k-1),f(a,i,j-1,k-1));
            r=max(t,s);
        }

        return d[i][j][k]=r;
    }

    int maximumAmount(vector<vector<int>>& a){
        int n=a.size(),m=a[0].size();

        d.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return f(a,n-1,m-1,2);
    }
};
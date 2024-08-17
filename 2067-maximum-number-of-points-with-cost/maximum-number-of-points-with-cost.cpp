class Solution {
public:
#define ll long long
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(),n=points[0].size();
        vector<ll>p(n);
        int score=0;
        
        for(int col=0;col<n;col++)p[col]=points[0][col];
        
        for(int i=1;i<m;i++){
            vector<ll>c(n);
            auto left=c,right=c;
            
            left[0]=p[0];
            for(int j=1;j<n;j++)left[j]=max(p[j],left[j-1]-1); 
            
            right[n-1]=p[n-1];
            for(int j=n-2;j>=0;j--)right[j]=max(p[j],right[j+1]-1);
            for(int j=0;j<n;j++)c[j]=points[i][j]+max(left[j],right[j]); 
            p=c;
        }
        
        return *max_element(p.begin(), p.end());
    }
};
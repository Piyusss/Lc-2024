class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size(),res=0;

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]) a[i][j]+=a[i-1][j];
            }
        }

        for(int i=0;i<m;i++){
            vector<int>v=a[i];
            sort(v.begin(),v.end());
            for(int j=0;j<n;j++) res=max(res,v[j]*(n-j));
        }

        return res;
    }
};
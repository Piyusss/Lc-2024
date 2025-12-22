class Solution {
public:
    int minDeletionSize(vector<string>&a) {
        int n=a.size(),m=a[0].size(),best=1;

        vector<int>d(m,1);
        for(int j=0;j<m;j++){
            for(int i=0;i<j;i++){
                bool ok=1;
                for(int r=0;r<n;r++){
                    if(a[r][i]>a[r][j]){
                        ok=0;
                        break;
                    }
                }
                if(ok)d[j]=max(d[j],d[i]+1);
            }
            best=max(best,d[j]);
        }

        return m-best;
    }
};
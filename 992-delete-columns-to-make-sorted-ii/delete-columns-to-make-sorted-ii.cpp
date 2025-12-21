class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n=a.size(),m=a[0].size(),r=0;

        vector<int>ok(n);
        for(int j=0;j<m;j++){
            bool f=1;

            for(int i=0;i<n-1;i++){
                if(ok[i])continue;
                if(a[i][j] > a[i+1][j]){
                    f=0;
                    break;
                }
            }

            if(f){
                for(int i=0;i<n-1;i++){
                    if(!ok[i] && a[i][j]<a[i+1][j]) ok[i]=1;
                }
            }
            else r++;
        }

        return r;
    }
};
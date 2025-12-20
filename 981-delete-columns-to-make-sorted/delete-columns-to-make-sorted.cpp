class Solution {
public:
    int minDeletionSize(vector<string>&v) {
        int cnt=0,n=v.size(),indSize=v[0].size();

        for(int i=0;i<indSize;i++){
            for(int j=0;j<n-1;j++){
                if(v[j+1][i]<v[j][i]){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};
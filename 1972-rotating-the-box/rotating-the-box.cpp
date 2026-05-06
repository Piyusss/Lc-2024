class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int m=a.size(),n=a[0].size();
        
        for(int i=0;i<m;i++){
            int e=n-1;
            for(int j=n-1;j>=0;j--){
                if(a[i][j]=='*') e=j-1;
                else if(a[i][j]=='#'){
                    a[i][j]='.';
                    a[i][e]='#';
                    e--;
                }
            }
        }

        vector<vector<char>>r(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                r[j][m-1-i]=a[i][j];
            }
        }

        return r;
    }
};
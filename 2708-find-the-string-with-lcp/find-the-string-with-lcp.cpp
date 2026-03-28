class Solution {
public:
    string findTheString(vector<vector<int>>& a) {
        int n=a.size();

        for(int i=0;i<n;i++){
            if(a[i][i] != n-i) return "";

            for(int j=0;j<n;j++){
                if(a[i][j] != a[j][i]) return "";
                if(a[i][j] > min(n-i,n-j)) return "";

                if(i+1<n && j+1<n){
                    if(a[i][j]>0){
                        if(a[i][j]!=a[i+1][j+1]+1) return "";
                    }
                }
                else{
                    if(a[i][j]>1) return "";
                }
            }
        }

        vector<vector<int>>g;
        vector<int>vis(n);

        function<void(int,vector<int>&)> dfs=[&](int u,vector<int>& v){
            vis[u]=1;
            v.push_back(u);
            for(int j=0;j<n;j++){
                if(a[u][j]>0 && !vis[j]) dfs(j,v);
            }
        };

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> v;
                dfs(i,v);
                g.push_back(v);
            }
        }

        vector<char>s(n);
        char c='a';

        for(auto &v:g){
            if(c>'z') return "";
            for(auto &x:v) s[x]=c;
            c++;
        }

        string r(s.begin(),s.end());
        vector<vector<int>>chk(n,vector<int>(n));

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(r[i]==r[j]){
                    if(i+1<n&&j+1<n) chk[i][j]=chk[i+1][j+1]+1;
                    else chk[i][j]=1;
                }
                else chk[i][j]=0;
            }
        }

        if(chk!=a) return "";
        return r;
    }
};
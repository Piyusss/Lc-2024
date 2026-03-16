class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();

        set<int>s;
        vector<int>r;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                s.insert(g[i][j]);

                for(int k=1;;k++){
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n) break;
                    int sum=0,x=i-k,y=j;

                    for(int t=0;t<k;t++) sum+=g[x++][y++];
                    for(int t=0;t<k;t++) sum+=g[x++][y--];
                    for(int t=0;t<k;t++) sum+=g[x--][y--];
                    for(int t=0;t<k;t++) sum+=g[x--][y++];

                    s.insert(sum);
                }
            }
        }

        for(auto it=s.rbegin();it!=s.rend() && r.size()<3;it++) r.push_back(*it);

        return r;
    }
};
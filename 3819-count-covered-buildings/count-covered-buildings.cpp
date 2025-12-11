class Solution{
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<int>lx(n+1,n+1),rx(n+1,0),ly(n+1,n+1),ry(n+1,0);

        for(auto &v:b){
            int x=v[0],y=v[1];
            lx[y]=min(lx[y],x);
            rx[y]=max(rx[y],x);
            ly[x]=min(ly[x],y);
            ry[x]=max(ry[x],y);
        }

        int r=0;
        for(auto &v:b){
            int x=v[0],y=v[1];
            if(lx[y]<x && x<rx[y] && ly[x]<y && y<ry[x])r++;
        }

        return r;
    }
};
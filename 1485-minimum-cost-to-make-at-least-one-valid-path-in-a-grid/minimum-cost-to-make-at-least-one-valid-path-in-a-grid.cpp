class Solution {
public:
#define ll long long


vector<vector<ll>>dir={{0,1},{0,-1},{-1,0},{1,0}};



    int minCost(vector<vector<int>>& grid) {
        ll n=grid.size();
        ll m=grid[0].size();

        vector<vector<ll>>dis(n,vector<ll>(m,1e9) );
        dis[0][0]=0;

        deque<pair<ll,ll>>dq;
        dq.push_front({0,0});

        while(!dq.empty()){
            ll xCor=dq.front().first;
            ll yCor=dq.front().second;
            ll val=grid[xCor][yCor];

            dq.pop_front();

            ll onxCor=-1,onyCor=-1;
            if(val==1){
                onxCor=xCor;
                onyCor=yCor+1;
            }
            else if(val==2){
                onxCor=xCor;
                onyCor=yCor-1;
            }
            else if(val==3){
                onxCor=xCor+1;
                onyCor=yCor;
            }
            else{
                onxCor=xCor-1;
                onyCor=yCor;
            }

            //now
            for(auto it:dir){
                ll nxCor=xCor+it[0];
                ll nyCor=yCor+it[1];

                if(nxCor>=0 && nxCor<n && nyCor>=0 && nyCor<m){


                    if(nxCor==onxCor && nyCor==onyCor){
                        if(dis[xCor][yCor]+0 < dis[nxCor][nyCor]){
                            dis[nxCor][nyCor]=dis[xCor][yCor]+0;
                            dq.push_front({nxCor,nyCor});
                        }
                    }

                    else{
                        if(dis[xCor][yCor]+1 < dis[nxCor][nyCor]){
                            dis[nxCor][nyCor]=dis[xCor][yCor]+1;
                            dq.push_back({nxCor,nyCor});
                        }
                    }



                }
            }
        }


        return dis[n-1][m-1];
    }
};
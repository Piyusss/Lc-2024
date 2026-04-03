using ll=long long;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int m=robots.size();
        if(m==0) return 0;

        vector<pair<ll,int>>r(m);
        for(int i=0;i<m;i++) r[i]={robots[i],distance[i]};
        sort(r.begin(),r.end());

        vector<ll>pos(m);
        vector<int>d(m);

        for(int i=0;i<m;i++){
            pos[i]=r[i].first;
            d[i]=r[i].second;
        }

        sort(walls.begin(),walls.end());
        vector<int>wf;
        wf.reserve(walls.size());

        int ri=0, walls_at_robot=0;
        for(auto &w:walls){
            while(ri < m && pos[ri]<w) ri++;
            if(ri<m && pos[ri]==w) walls_at_robot++;
            else wf.push_back(w);
        }

        auto count_range=[&](ll L,ll R)->int{
            if(L>R || wf.empty()) return 0;
            auto itl=lower_bound(wf.begin(),wf.end(),(int)max(L,(ll)INT_MIN));
            auto itr=upper_bound(wf.begin(),wf.end(),(int)min(R,(ll)INT_MAX));
            return int(itr-itl);
        };


        vector<int>cntL(m),cntR(m),both(m-1);

        for(int i=0;i<m-1;i++){
            ll L=pos[i]+1, R=pos[i+1]-1;

            if(L>R){cntL[i]=cntR[i+1]=both[i]=0;continue;}

            ll upL=min(pos[i]+(ll)d[i],R);
            cntL[i]=count_range(L,upL);

            ll lowR=max(pos[i+1]-(ll)d[i+1],L);
            cntR[i+1]=count_range(lowR,R);

            ll bL=max(L,lowR),bR=min(upL,R);
            both[i]=count_range(bL,bR);
        }

        ll left_end=count_range(pos[0]-(ll)d[0],pos[0]-1);
        ll right_end=count_range(pos[m-1]+1,pos[m-1]+(ll)d[m-1]);

        vector<ll>prev(2,LLONG_MIN/4),cur(2,LLONG_MIN/4);
        prev[0]=left_end;
        prev[1]=0;

        for(int i=1;i<m;i++){
            cur[0]=cur[1]=LLONG_MIN/4;
            int g=i-1;

            for(int pc=0;pc<2;pc++){
                for(int cc=0;cc<2;cc++){
                    ll add=0;
                    ll lc=(pc==1)?cntL[g]:0, rc=(cc==0)?cntR[i]:0;
                    ll overlap=(pc==1 && cc==0) ? both[g] : 0;
                    add=lc+rc-overlap;
                    cur[cc]=max(cur[cc],prev[pc]+add);
                }
            }

            prev=cur;
        }

        ll best=max(prev[0],prev[1]+right_end);
        best += walls_at_robot;

        return (int)best;
    }
};
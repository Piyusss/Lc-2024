using ll=long long;
const int M=1E9+7;

class Solution{
public:
    int countTrapezoids(vector<vector<int>>& a) {
        unordered_map<ll,ll>m;
        ll t=0;

        for(auto &u:a){
            ll y=u[1];
            t=(t+m[y])%M;
            m[y]++;
        }

        ll w=t*((t-1+M)%M)%M;
        w*=((M+1)/2)%M;

        for(auto &q:m){
            ll c=q.second;
            if(c>1){
                ll x=c*(c-1)/2%M;
                ll y=x*((x-1+M)%M)%M;

                y=y*((M+1)/2)%M;
                w=(w-y+M)%M;
            }
        }

        return (int)w;
    }
};
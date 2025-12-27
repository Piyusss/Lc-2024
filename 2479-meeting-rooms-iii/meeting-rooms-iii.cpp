using ll=long long;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>&a) {
        sort(a.begin(),a.end());
        vector<ll>t(n),c(n);

        for(auto &v:a){
            int s=v[0],e=v[1],d=e-s;
            int r=-1;

            ll mn=LLONG_MAX;
            for(int i=0;i<n;i++){
                if(t[i]<=s){
                    r=i;
                    break;
                }
                if(t[i]<mn){
                    mn=t[i];
                    r=i;
                }
            }
            if(t[r]<=s)t[r]=e;
            else t[r]+=d;
            
            c[r]++;
        }

        ll ans=0;
        for(int i=1;i<n;i++) if(c[i]>c[ans]) ans=i;
        return ans;
    }
};
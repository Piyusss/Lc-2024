using ll=long long;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        unordered_map<ll,ll>f;

        for(auto &x:a) f[x]++;

        ll ans=1;
        for(auto &[k,v]:f){
            if(k==1){
                if(v&1) ans=max(ans,v);
                else ans=max(ans,v-1);
                continue;
            }

            if(v<2) continue;
            ll c=2,x=k*k;

            while(f.count(x)){
                if(f[x]==1){
                    c++;
                    break;
                }

                c+=2;
                x*=x;
            }

            if(!(c&1)) c--;
            ans=max(ans,c);
        }

        return ans;
    }
};
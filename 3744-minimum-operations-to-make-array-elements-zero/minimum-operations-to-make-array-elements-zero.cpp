using ll=long long;

class Solution {
public:

    ll f(ll x){
        ll a=0,b=1,c=0;
        
        while(c<x){
            ll d=min(x,(c+1)*4-1);
            a+=(d-c)*b;
            c=d;
            b++;
        }
        return a;
    }

    long long minOperations(vector<vector<int>>& q){
        ll r=0;

        for(auto &v:q){
            ll s=f(v[1])-f(v[0]-1);
            r+=(s+1)/2;
        }

        return r;
    }
};

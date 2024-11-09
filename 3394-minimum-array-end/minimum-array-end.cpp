class Solution {
public:

#define ll long long

    ll minEnd(int n, int x){

        ll res=x;
        for(ll i=1;i<=n-1;i++) res = (res+1) | x;
        return res;
        
    }
};
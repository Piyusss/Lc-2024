class Solution {
public:

#define ll long long

ll f(ll cur,ll next,int n) {
    ll cnt=0;

    while(cur<=n){
        cnt +=(next-cur);
        cur *=10,next*=10;
        next =min(next,(ll)n+1);
    }
    return cnt;
}

    int findKthNumber(int n, int k) {
        ll cur=1;
        k--;

        while(k){
            ll count=f(cur,cur+1,n);
            if(count <= k) cur++, k-=count; 
            else cur *= 10,k--;
        }

        return cur;
    }
};
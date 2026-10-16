using ll=long long;
const ll mod=1E9+7;

class Solution {
public:
    int sumCounts(vector<int>& a) {
        int n=a.size();

        vector<ll>c(n+1),t(n+1);
        unordered_map<int,int>l;

        ll ans=0,x=0,y=0,len=0,g=0;

        for(int r=0;r<n;r++){
            int p=l.count(a[r])?l[a[r]]:-1;
            x=0,y=0;

            for(int i=n-p-1;i>0;i-=i&-i){
                x+=c[i];
                y+=t[i];
            }

            len=r-p,g=len*len-2*(y-p*x);
            ans=(ans+(n-r)*g)%mod;

            for(int i=n-p;i<=n;i+=i&-i){
                c[i]++;
                t[i]+=p;
            }

            l[a[r]]=r;
        }

        return ans;
    }
};
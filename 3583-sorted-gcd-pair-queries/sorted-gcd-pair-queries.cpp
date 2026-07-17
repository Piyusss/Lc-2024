using ll=long long;

class Solution {
public:
    vector<int> gcdValues(vector<int>& a,vector<long long>& q) {
        int m=*max_element(a.begin(),a.end());

        vector<int>f(m+1);
        for(auto &x:a) f[x]+=1;

        vector<int>d(m+1);

        for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) d[i]+=f[j];

        vector<ll>c(m+1);

        for(int i=m;i>=1;i--){
            ll x=d[i];
            c[i]=x*(x-1)/2;
            for(int j=i+i;j<=m;j+=i) c[i]-=c[j];
        }

        vector<ll>p(m+1);
        for(int i=1;i<=m;i++) p[i]=p[i-1]+c[i];

        vector<int>r;
        for(auto &x:q){
            int l=1,h=m;

            while(l<h){
                int md=(l+h)>>1;

                if(p[md]>x) h=md;
                else l=md+1;
            }

            r.push_back(l);
        }

        return r;
    }
};
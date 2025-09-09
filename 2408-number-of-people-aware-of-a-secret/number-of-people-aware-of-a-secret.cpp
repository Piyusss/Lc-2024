using ll=long long;
const int MOD=1000000007;

class Solution{
public:
    int peopleAwareOfSecret(int n, int delay, int forget){
        vector<ll>know(n);
        know[0]=1;
        ll active=0;
        
        for(int day=1;day<n;day++){
            if(day-delay>=0) active=(active+know[day-delay])%MOD;
            if(day-forget>=0) active=(active-know[day-forget]+MOD)%MOD;
            know[day]=active;
        }

        ll res=0;
        for(int day=n-forget;day<n;day++) if(day>=0) res=(res+know[day])%MOD;
        return (int)res;
    }
};

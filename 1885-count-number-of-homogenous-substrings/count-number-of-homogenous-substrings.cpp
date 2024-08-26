class Solution {
public:

int M=1E9+7;
#define ll long long
    int countHomogenous(string s){
        ll n=s.size();

        ll cnt=1;
        ll res=0;

        for(ll i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                ll wait=(cnt)*(cnt+1)/2;
                wait=wait%M;
                res= (res%M+ wait%M )%M;
                cnt=1;
            }
        }

        ll wait=((cnt%M)*((cnt+1)%M)/2)%M;
        wait=wait%M;
        res= (res%M+ wait%M )%M;

        return res%M;
    }
};
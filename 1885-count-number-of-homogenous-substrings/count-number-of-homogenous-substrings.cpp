class Solution {
public:

int M=1E9+7;
#define ll long long
    int countHomogenous(string s){
        ll n=s.size();

        ll cnt=1;
        ll res=0;

        for(ll i=0;i<n-1;i++){
            if(s[i]==s[i+1]) cnt++;
            else res= (res%M+ ((cnt)*(cnt+1)/2)%M )%M,cnt=1;
        }

        res= (res%M+ ((cnt)*(cnt+1)/2)%M )%M;

        return res%M;
    }
};
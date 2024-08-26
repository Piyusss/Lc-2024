class Solution {
public:

int M=1E9+7;
#define ll long long

    int numSub(string s) {
        ll n=s.size();

        ll cnt=1;
        ll res=0;
        ll flag= s[0]=='0' ? 0 : 1 ;

        for(ll i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                if(flag) res= (res%M+ ((cnt)*(cnt+1)/2)%M )%M;
                flag=!flag;
                cnt=1;
            }
        }

        if(flag) res= (res%M+ ((cnt)*(cnt+1)/2)%M )%M;

        return res%M;
    }
};
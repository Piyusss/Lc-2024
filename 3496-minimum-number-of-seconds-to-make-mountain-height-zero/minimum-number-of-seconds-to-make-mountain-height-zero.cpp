using ll=long long;

class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& work) {
        int n=work.size();
        ll low=0,high=1E18;

        ll ans=0;
        while(low<=high){
            ll mid=(low+high)>>1;
            ll cnt=0;

            for(int i=0;i<n;i++){
                ll low1=0,high1=1e6;
                ll ans1=0;

                while(low1<=high1){
                    ll mid1=(low1+high1)>>1;
                    if(mid1*(mid1+1)*work[i]>2*mid) high1=mid1-1;
                    else{
                        ans1=mid1;
                        low1=mid1+1;
                    }
                }   

                cnt += ans1;             
            }

            if(cnt>=height){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }

        return ans;
    }
};
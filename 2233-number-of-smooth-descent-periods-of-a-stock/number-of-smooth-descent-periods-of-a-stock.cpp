using ll=long long;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll n=prices.size();

        ll cnt=1,ans=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]-prices[i]==1)cnt++;
            else{
                ans+=((cnt)*(cnt+1))>>1;
                cnt=1;
            }
        }

        ans+=((cnt)*(cnt+1))>>1;
        return ans;
    }
};
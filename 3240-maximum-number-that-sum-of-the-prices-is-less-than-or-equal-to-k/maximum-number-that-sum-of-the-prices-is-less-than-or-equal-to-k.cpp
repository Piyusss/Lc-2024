class Solution {
public:

using ll = long long;
vector<ll>bitCount;

void getBits(ll num){
    if(num==0)return;
    if(num==1){
        bitCount[0]++;
        return;
    }
    if(num==2){
        bitCount[0]++;
        bitCount[1]++;
        return;
    }

    ll bitLen=log2(num);
    ll nearestPowerOfTwo=(1ll<<bitLen);
    bitCount[bitLen]+=(num-nearestPowerOfTwo+1);

    for(int i=0;i<bitLen;i++){
        bitCount[i]+=(nearestPowerOfTwo/2);
    }
    num=num-nearestPowerOfTwo;
    getBits(num);
}

    long long findMaximumNumber(long long k, int x) {
        ll low=0,high=1e15;

        ll res=0;
        while(low<=high){
            ll mid=low+(high-low)/2;

            bitCount=vector<ll>(65,0);

            getBits(mid);

            ll accumulatedCount=0;
            for(ll i=0;i<log2(mid)+1;i++){
                if((i+1)%x==0){
                    accumulatedCount+=bitCount[i];
                }
            }

            if(accumulatedCount<=k){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return res;
    }
};
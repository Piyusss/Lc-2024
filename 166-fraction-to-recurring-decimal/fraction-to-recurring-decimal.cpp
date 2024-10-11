class Solution {
public:

#define ll long long

    string fractionToDecimal(int N, int D) {
        if(N==0) return "0";

        string res="";

        if((N<0 ^ D<0)) res+="-";

        ll n=abs((ll)N);
        ll d=abs((ll)D);
        ll rem=n%d;
        res+=to_string(abs(n/d));

        if(rem==0) return res;

        res+=".";

        unordered_map<ll,ll>mp;
        while(rem){
            if(mp.find(rem)!=mp.end()){
                res.insert(mp[rem],"(");
                res+=")";
                return res;
            }

            mp[rem]=res.size();
            rem*=10;
            res+=to_string(rem/d);
            rem%=d;
        }

        return res;

    }
};

// 4->2, rem=40, res+=0, rem=40
// 40->3, rem=400, res+=1, rem=67
// 67->4, rem=670, res+=2, rem=4
// 4->!, 4 already in map , mp[4]=2, 
const int M=1E9+7;
using ll=long long;

class Solution {
public:
    int countPermutations(vector<int>& c) {
        int n=c.size();

        ll f=c[0];
        ll com=*min_element(c.begin()+1,c.end());
        if(f>=com) return 0;

        ll res=1;
        for(int i=1;i<=n-1;i++){
            res *= i;
            res %= M;
        }

        return res;
    }
};
const int m=1E9+7;;
using ll=long long;

class Solution {
public:

    int countPartitions(vector<int>& a, int k) {
        int n=a.size();

        vector<int>d(n+1),p(n+1);
        d[0]=p[0]=1;

        multiset<int>s;
        int L=0;

        for(int R=1;R<=n;R++){
            s.insert(a[R-1]);

            while(*s.rbegin()-*s.begin()>k){
                s.erase(s.find(a[L]));
                L++;
            }

            int x=(L?p[L-1]:0);
            d[R]=(p[R-1]-x+m)%m;
            p[R]=(p[R-1]+d[R])%m;
        }

        return d[n];
    }
};
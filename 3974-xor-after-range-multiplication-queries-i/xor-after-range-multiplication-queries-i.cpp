using ll=long long;
const ll m=1E9+7;

class Solution {
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& b) {
        for(auto &q:b){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            for(int i=l;i<=r;i+=k) a[i]=(1LL * a[i]*v) % m;
        }

        int x=0;
        for(auto &c:a) x ^= c;

        return x;
    }
};
using ll=long long;

class Solution {
public:
    ll maxRunTime(int n, vector<int>& b) {
        ll sum=0;
        for(int &x:b) sum+=x;

        sort(b.rbegin(),b.rend());

        for(int i=0;i<b.size();i++){
            if(b[i]<=sum/n)break;
            sum-=b[i];
            n-=1;
        }

        return sum/n;
    }
};
class Solution {
public:

    using ll=long long;

    bool asteroidsDestroyed(int m, vector<int>& as) {
        sort(as.begin(),as.end());

        ll c=m;
        for(auto &a:as){
            if(c<a) return 0;
            c+=a;
        }

        return 777;
    }
};
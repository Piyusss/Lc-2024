using ll=long long;

class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        int n=a.size();

        vector<ll>res(n);
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++) mp[a[i]].push_back(i);

        for(auto &it:mp){
            auto &v=it.second;
            ll tot=0,ls=0;

            for(int &x:v) tot+=x;
            int sz=v.size();

            for(int i=0;i<sz;i++){
                ll cur=v[i],rs=tot-ls-cur;
                ll l=cur*i-ls,r=rs-cur*(sz-i-1);

                res[cur]=l+r;
                ls+=cur;
            }
        }

        return res;
    }
};
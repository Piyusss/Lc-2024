class Solution {
public:
    vector<int> solveQueries(vector<int>& a,vector<int>& q) {
        int n=a.size();

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[a[i]].push_back(i);

        vector<int>r;
        for(int x:q){
            auto &v=mp[a[x]];
            int s=v.size();

            if(s<=1){
                r.push_back(-1);
                continue;
            }

            int i=lower_bound(v.begin(),v.end(),x)-v.begin(),p=v[(i-1+s)%s];
            int nx=v[(i+1)%s],l=abs(x-p),rr=abs(nx-x);
            
            l=min(l,n-l);
            rr=min(rr,n-rr);
            r.push_back(min(l,rr));
        }

        return r;
    }
};
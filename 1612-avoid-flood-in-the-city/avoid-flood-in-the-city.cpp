class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        int n=r.size();
        vector<int>ans(n,1);

        unordered_map<int,int>full;
        set<int>free;

        for(int d=0;d<n;d++){
            int x=r[d];

            if(x==0){
                free.insert(d);
                continue;
            }

            ans[d]=-1;

            if(full.count(x)){
                auto pos=free.upper_bound(full[x]);
                if(pos==free.end())return {};
                ans[*pos]=x;
                free.erase(pos);
            }
            full[x]=d;
        }

        return ans;
    }
};
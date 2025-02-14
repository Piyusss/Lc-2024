class Solution {
public:

vector<int>res;

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>st;
        for(int i=0;i<n;i++) st.insert(i);

        for(auto &q:queries){
            int u=q[0];
            int v=q[1];

            auto nextToU=st.upper_bound(u);
            while(*nextToU<v) st.erase(nextToU++);

            res.push_back(st.size()-1);
        }

        return res;
    }
};
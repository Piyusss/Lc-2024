class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return (a[1]-a[0])>(b[1]-b[0]);
    }

    int minimumEffort(vector<vector<int>>& t) {
        sort(t.begin(),t.end(),comp);

        int ans=0,rem=0;

        for(auto &v:t){
            if(rem<v[1]) ans+=v[1]-rem;
            rem=max(v[1]-v[0],rem-v[0]);
        }

        return ans;
    }
};
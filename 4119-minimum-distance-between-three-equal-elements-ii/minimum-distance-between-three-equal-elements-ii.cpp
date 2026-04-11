class Solution {
public:
    int minimumDistance(vector<int>& v) {
        int n=v.size(),ans=INT_MAX;

        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[v[i]].push_back(i);

            if(m[v[i]].size()==3){
                ans=min(ans,2*(m[v[i]][2]-m[v[i]][0]));
                m[v[i]].erase(m[v[i]].begin());
            }

        }

        return (ans==INT_MAX?-1:ans);
    }
};
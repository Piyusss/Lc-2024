class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)return n;
        int res=2;

        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dx=points[j][0]-points[i][0];
                    int dy=points[j][1]-points[i][1];
                    auto slope=atan2(dy,dx);
                    mp[slope]++;
                }
            }
            for(auto it:mp)res=max(res,it.second+1);
        }

        return res;
    }
};
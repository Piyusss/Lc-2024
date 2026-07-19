class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;

        int n=points.size();

        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];

            int ed=x*x+y*y;

            pq.push({ed,{x,y}});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
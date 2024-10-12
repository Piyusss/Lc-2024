class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it:intervals){
            int start=it[0];
            int end=it[1];

            if(!pq.empty() && start>pq.top())pq.pop();
            pq.push(end);
        }

        return pq.size();
    }
};
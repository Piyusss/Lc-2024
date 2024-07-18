class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<profit.size();i++)pq.push({profit[i],difficulty[i]});

        sort(worker.begin(),worker.end(),greater<int>());

        int ans=0;

        for(int i=0;i<worker.size();i++){
            while(!pq.empty() && pq.top().second>worker[i])pq.pop();
            if(!pq.empty())ans+=pq.top().first;
        }

        return ans;
    }
};
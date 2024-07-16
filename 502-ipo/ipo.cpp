class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        vector<pair<int,int>>cost(n);

        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            cost[i]={capital[i],profits[i]};
        }

        sort(cost.begin(),cost.end());

        int mark=0;
        for(int i=0;i<k;i++){

            while(mark<n && w>=cost[mark].first){
                pq.push(cost[mark].second);
                mark++;
            }

            if(pq.empty())break;

            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};
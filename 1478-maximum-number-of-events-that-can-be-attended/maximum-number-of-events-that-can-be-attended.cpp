class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());

        int startDay=events[0][0];
        int endDay=-1;
        for(auto &c:events) endDay=max(endDay,c[1]);

        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;

        int cnt=0;
        for(int day=startDay;day<=endDay || !(i==n && pq.empty());day+=1){
            while(i<n && events[i][0]==day) pq.push(events[i++][1]);
            while(!pq.empty() && pq.top()<day) pq.pop();

            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};
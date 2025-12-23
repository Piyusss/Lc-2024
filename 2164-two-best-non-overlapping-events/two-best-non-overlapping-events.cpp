class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        int maxVal=0,ans=0;
        for(auto &c:events){
            int srt=c[0],end=c[1],val=c[2];

            while(!pq.empty() && pq.top().first < srt){
                maxVal=max(maxVal,pq.top().second);
                pq.pop();
            }

            ans=max(ans,maxVal+val);
            pq.push({end,val});
        }

        return ans;
    }
};
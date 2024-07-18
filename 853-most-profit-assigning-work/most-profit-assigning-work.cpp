class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;

        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());

        int ans=0;
        int tempProfit=0;
        int j=0;
        for(auto &it:worker){
            while(j<v.size() && it>=v[j].first){
                tempProfit=max(tempProfit,v[j].second);
                j++;
            }
            ans+=tempProfit;
        }

        return ans;
    }
};
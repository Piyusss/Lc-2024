class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;

        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());

        for(int i=1;i<v.size();i++)v[i].second=max(v[i].second,v[i-1].second);

        int ans=0;
        for(auto &it:worker){
            int l=0;
            int r=v.size()-1;
            int maxProfit=0;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(v[mid].first<=it){
                    maxProfit=max(maxProfit,v[mid].second);
                    l=mid+1;
                }
                else r=mid-1;
            }

            ans+=maxProfit;
        }

        return ans;
    }
};
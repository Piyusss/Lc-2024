class Solution {
public:

    static bool comp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
        return a.first.second<b.first.second;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int n=intervals.size();
        vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        
        sort(v.begin(),v.end(),comp);
        
        int cnt=1;
        vector<int>ans;
        ans.push_back(v[0].second);
        
        int curEnd=v[0].first.second;
        for(int i=1;i<n;i++){
            if(v[i].first.first>=curEnd){
                cnt++;
                ans.push_back(v[i].second);
                curEnd=v[i].first.second;
            }
        }
        
        // for(auto it:ans)cout<<it<<" ";
        
        return n-cnt;
    }
};
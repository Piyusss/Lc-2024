class Solution {
public:

static bool comp(pair<string,int>& a,pair<string,int>& b){
    return a.second>b.second;
}
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<pair<string,int>>pairs;
        for(int i=0;i<names.size();i++)pairs.push_back({names[i],heights[i]});
        sort(pairs.begin(),pairs.end(),comp);

        for(int i=0;i<pairs.size();i++)ans.push_back(pairs[i].first);
        return ans;
    }
};
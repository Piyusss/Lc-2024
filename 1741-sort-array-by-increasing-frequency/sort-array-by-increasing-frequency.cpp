class Solution {
public:

static bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)return a>b;
    else return a.second<b.second;
}
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;

        for(auto it:nums)mp[it]++;

        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }

        sort(v.begin(),v.end(),comp);

        vector<int>ans;

        for(auto it:v){
            int loop=it.second;
            while(loop--)ans.push_back(it.first);
        }

        return ans;
    }
};
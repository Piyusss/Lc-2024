class Solution {
public:

static bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.first!=b.first) return a.first>b.first; //freq not equal to jo jyada wo pehle
    return a.second>b.second;
}
    vector<int> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();

        vector<int>res;

        for(int i=0;i<=n-k;i++){
            unordered_map<int,int>mp;
            int excSum=0;
            for(int j=i;j<i+k;j++) mp[nums[j]]++,excSum+=nums[j];
            if(mp.size()<x){
                res.push_back(excSum);
                continue;
            }
            
            vector<pair<int,int>>v;
            for(auto &it:mp)v.push_back({it.second,it.first}); //freq,el

            sort(v.begin(),v.end(),comp);

            int sum=0;
            for(int i=0;i<x;i++)sum+=v[i].first*v[i].second;

            res.push_back(sum);
        }

        return res;
    }
};
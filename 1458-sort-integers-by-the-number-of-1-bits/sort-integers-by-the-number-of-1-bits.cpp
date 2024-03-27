class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({__builtin_popcount(arr[i]),arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto it:v){
            ans.push_back(it.second);
        }
        return ans;
    }
};
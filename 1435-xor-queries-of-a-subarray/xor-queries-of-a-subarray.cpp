class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();

        int s=arr[0];
        vector<int>v;
        v.push_back(s);
        
        for(int i=1;i<n;i++){
            s=s^arr[i];
            v.push_back(s);
        }

        vector<int>ans;
        for(auto &it:queries){
            ans.push_back(it[0]>=1 ? v[it[1]] ^ v[it[0]-1] : v[it[1]]);
        }

        return ans;
    }
};
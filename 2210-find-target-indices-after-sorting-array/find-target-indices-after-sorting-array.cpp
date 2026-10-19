class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int t) {
        int n=a.size();

        sort(a.begin(),a.end());
        vector<int>ans;

        for(int i=0;i<n;i++) if(a[i]==t) ans.push_back(i);
        return ans;
    }
};
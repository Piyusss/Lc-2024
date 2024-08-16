class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=0;
        int maxi=arrays[0].back();
        int mini=arrays[0].front();

        for(int i=1;i<arrays.size();i++){
            int cur_maxi=arrays[i].back();
            int cur_mini=arrays[i].front();

            ans=max(ans,abs(cur_maxi-mini));
            ans=max(ans,abs(cur_mini-maxi));

            maxi=max(maxi,cur_maxi);
            mini=min(mini,cur_mini);
        }

        return ans;
    }
};
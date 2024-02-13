class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int start=nums[i][0];
            int end=nums[i][1];
            if(!ans.empty() && end<=ans.back()[1])continue;

            for(int j=i+1;j<n;j++){
                if(nums[j][0]<=end)end=max(end,nums[j][1]);
                else break;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
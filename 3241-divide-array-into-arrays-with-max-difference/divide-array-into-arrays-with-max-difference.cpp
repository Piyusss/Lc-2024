class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int nn=nums.size();
        if(nn%3!=0)return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nn;i+=3) {
            if (i + 2 < nn && nums[i + 2] - nums[i] <= k) {
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
            }
            else{
                result.clear();
                break;
            }
        }
        return result;
    }
};
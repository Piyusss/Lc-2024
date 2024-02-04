class Solution {
public:
void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans=permute(nums);
        set<vector<int>>st;
        for(auto it:ans)st.insert(it);
        ans.clear();
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};
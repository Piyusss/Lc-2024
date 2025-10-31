class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();

        vector<int>res;
        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==2) res.push_back(nums[i]);
        }

        return res;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        vector<pair<int,int>>p_nums;
        for(int i=0;i<n;i++) p_nums.push_back({nums[i],i});
        sort(p_nums.begin(),p_nums.end());

        int l=0,r=n-1;

        while(l<r){
            int sum=p_nums[l].first+p_nums[r].first;
            if(sum==target) return {p_nums[l].second,p_nums[r].second};
            else if(sum<target) l++;
            else r--;
        }

        return {};
    }
};
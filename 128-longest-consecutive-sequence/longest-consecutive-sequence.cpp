class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        set<int>st;
        for(auto it:nums)st.insert(it);
        nums.clear();
        for(auto it:st)nums.push_back(it);
        int maxi=0;
        int cnt=1;
        int n=nums.size();
        if(n==1)return 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]+1==nums[i+1])cnt++;
            else cnt=1;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
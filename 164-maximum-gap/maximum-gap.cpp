class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();

        if(n<2) return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;

        for(int i=0;i<n-1;i++){
            maxi=max(maxi,abs(nums[i+1]-nums[i]));
        }   
        return maxi;
    }
};
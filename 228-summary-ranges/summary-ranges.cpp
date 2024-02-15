class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>v;
        if(n==0)return v;
        int start=nums[0];int end=nums[0];
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(start==end)v.push_back(to_string(nums[n-1]));
                else v.push_back(to_string(start)+"->"+to_string(end));
            }
            else if(nums[i]+1==nums[i+1])end=nums[i+1];
            else{
                if(start==end)v.push_back(to_string(start));
                else v.push_back(to_string(start)+"->"+to_string(end));
                start=nums[i+1];
                end=nums[i+1];
            }
        }
        return v;
    }
};
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        //now
        int maxi=INT_MIN;int flag=0;
        for(int i=0;i<n;i++){
            for(int j=flag;j<n;j++){
                mp[nums[j]]++;
                if(mp[nums[j]]<=k)maxi=max(maxi,j-i+1);
                else{
                    flag=j;
                    break;
                }
            }
            mp[nums[i]]--;
            mp[nums[flag]]--;
        }
        return maxi;
    }
};
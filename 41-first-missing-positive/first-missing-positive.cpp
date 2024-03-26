class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int check=1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>0 && mp[nums[i]]==0){
                if(nums[i]==check){
                    mp[nums[i]]=1;
                    check++;
                    continue;
                }
                else break;
            }
        }
        return check;
    }
};
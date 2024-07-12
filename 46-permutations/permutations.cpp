class Solution {
public:
void f(vector<int>&ds,vector<vector<int>>&ans,vector<int>nums,map<int,int>&mp){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i=0;i<nums.size();i++){
        if(!mp[nums[i]]){
            ds.push_back(nums[i]);mp[nums[i]]=1;
            f(ds,ans,nums,mp);
            mp[nums[i]]=0;ds.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        map<int,int>mp;
        f(ds,ans,nums,mp);
        return ans;
    }
};
class Solution {
public:

void f(int idx,vector<int>& nums,int n,vector<int> &vis){
    if(idx<0 || idx>=n || vis[idx])return;

    vis[idx]=1;
    f(idx+nums[idx],nums,n,vis);
    f(idx-nums[idx],nums,n,vis);

}
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<int>vis(n,0);
        f(start,nums,n,vis);

        for(int i=0;i<n;i++)if(nums[i]==0 && vis[i])return 1;
        return 0;
    }
};
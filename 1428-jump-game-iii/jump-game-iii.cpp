class Solution {
public:

int vis[50000+2];

void f(int idx,vector<int>& nums,int n){
    if(idx<0 || idx>=n || vis[idx])return;

    vis[idx]=1;
    f(idx+nums[idx],nums,n);
    f(idx-nums[idx],nums,n);

}
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        memset(vis,0,sizeof(vis));
        f(start,nums,n);

        for(int i=0;i<n;i++)if(nums[i]==0 && vis[i])return 1;
        return 0;
    }
};
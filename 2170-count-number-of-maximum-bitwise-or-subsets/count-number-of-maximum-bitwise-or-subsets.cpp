class Solution {
public:

int t,n,cnt=0;

void f(vector<int>&nums,int idx,int res){
    if(idx==n){
        if(res == t) cnt++;
        return;
    }

    f(nums,idx+1,res | nums[idx]);
    f(nums,idx+1,res);

}

    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();

        t=nums[0];
        for(int i=1;i<n;i++) t = t | nums[i];

        int res=0;
        f(nums,0,res);

        return cnt;
        
    }
};
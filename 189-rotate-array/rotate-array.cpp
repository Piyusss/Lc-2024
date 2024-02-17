class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n);
        int s=0;
        //now
        int diff=k-n;
        while(diff>n)diff-=n;
        if(n<k)k=diff;
        for(int i=0;i<n;i++){
            int p=i+k;
            if(p>=n){
                p=s;
                s++;
            }
            ans[p]=nums[i];
        }
        nums=ans;
    }
};
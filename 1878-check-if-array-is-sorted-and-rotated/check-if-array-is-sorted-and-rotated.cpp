class Solution {
public:
    bool f(vector<int>v){
        int flag=0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]<v[i]){
                return 0;
            }
        }
        return 1;
}
    vector<int> rotate(vector<int>nums, int k) {
        int n=nums.size();
        vector<int>ans(n);
        int s=0;
        //now
        int diff=k-n;
        while(diff>n)diff-=n;
        if(n<k)k=diff;
        for(int i=0;i<n;i++){
            int p=i+k;
            if(p>=n)p=s++;
            ans[p]=nums[i];
        }
    return ans;
   }
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int k=0;k<n;k++){
            vector<int>rotated=rotate(nums,k);
            if(f(rotated))return 1;
        }
        return 0;
    }
};
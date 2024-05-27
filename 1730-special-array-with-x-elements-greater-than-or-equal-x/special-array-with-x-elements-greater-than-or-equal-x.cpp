class Solution {
public:
    int f(vector<int>nums,int x){
        int cnt=0;
        for(auto it:nums)if(it>=x)cnt++;
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<=n;i++){
            int freq=f(nums,i);
            if(freq==i)return i;
        }
        return -1;
    }
};
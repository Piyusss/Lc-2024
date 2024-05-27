class Solution {
public:
    int f(vector<int>nums,int x){
        int cnt=0;
        for(auto it:nums)if(it>=x)cnt++;
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        for(int i=1;i<=nums.size();i++)if(f(nums,i)==i)return i;
        return -1;
    }
};
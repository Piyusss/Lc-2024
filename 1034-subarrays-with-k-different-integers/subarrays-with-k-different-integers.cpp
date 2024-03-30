class Solution {
public:
int f(vector<int>nums,int k){
    int n=nums.size();
    unordered_map<int,int>mp;
    int i=0,j=0,cnt=0;
    while(j<n){
        mp[nums[j]]++;
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        //now
        // Method-01: Brute Force O(N^2)
        
        //Method-02: Sliding Window
        return f(nums,k)-f(nums,k-1);
    }
};
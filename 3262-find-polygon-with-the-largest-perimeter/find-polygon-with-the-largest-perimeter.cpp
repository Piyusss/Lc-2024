class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // 1 1 2 3 5 12 50
        //1 1 5 7
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        vector<long long>v;
        for(auto it:nums){
            v.push_back((long long)it);
            sum+=v.back();
        }
        int flag=0;
        for(long long i=n-1;i>=2;i--){
            sum-=nums[i];
            if(nums[i]<sum){
                sum+=nums[i];
                flag=1;
                break;
            };
        }
        if(flag==0)return -1;
        return sum;
    }
};
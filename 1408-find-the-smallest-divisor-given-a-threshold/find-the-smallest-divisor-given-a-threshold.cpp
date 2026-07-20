class Solution {
public:

    bool f(int mid,vector<int>&nums,int t){
        int tot=0;
        for(auto &c:nums) tot+=((c+mid-1)/mid);
        return tot<=t;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int n=nums.size();

        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int mid=-1;

        while(low<high){
            mid=low+(high-low)/2;

            if(f(mid,nums,t)) high=mid;
            else low=mid+1;
        }

        return high;
    }
};

// 1 2 5 9 | 6
// divisor 1 -> sum is (1+2+5+9)=17
// divisor 2 -> sum is (1+1+3+5)=10
// divisor 3 -> sum is (1+1+2+3)=7
// divisor 4 -> sum is (1+1+2+3)=7
// divisor 5 -> sum is (1+1+1+2)=5
// divisor 6 -> sum is (1+1+1+2)=5
// divisor 7 -> sum is (1+1+1+2)=5
// divisor 8 -> sum is (1+1+1+2)=5
// divisor 9 -> sum is (1+1+1+1)=4
// hence monotonicity is true.
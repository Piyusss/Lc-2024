class Solution {
public:
int f(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];int prev2=0;
        for(int i=1;i<=n-1;i++){
            int pick=nums[i];if(i>1)pick+=prev2;
            int notPick=0+prev;
            int cur=max(pick,notPick);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }

    int rob(vector<int>& nums){
        int n=nums.size();
        if(nums.size()==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        return max(f(temp1),f(temp2));
    }
};
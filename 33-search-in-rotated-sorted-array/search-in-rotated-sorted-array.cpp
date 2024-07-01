class Solution {
public:
void f(vector<int>&nums){
    //rotate-left
    int n=nums.size();
    int store=nums[0];
    for(int i=1;i<n;i++){
        nums[i-1]=nums[i];
    }
    nums[n-1]=store;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int mini=INT_MAX,cnt=0,fix=n,flag=0;
        while(fix--){
            int front=nums[0];
            if(target==front){
                flag=1;break;
            }
            if(front<mini)mini=front;
            cnt++;
            f(nums);
        }
        return flag ? cnt : -1;
    }
};
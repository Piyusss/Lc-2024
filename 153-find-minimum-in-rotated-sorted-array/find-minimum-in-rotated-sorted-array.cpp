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
    int findMin(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>st;
        int mini=INT_MAX;
        while(1){
            int front=nums[0];
            if(st.find(front)!=st.end())break;
            else st.insert(front);
            mini=min(mini,front);
            f(nums);
        }
        return mini;
    }
};
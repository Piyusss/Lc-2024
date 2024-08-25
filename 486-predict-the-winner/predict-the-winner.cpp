class Solution {
public:
int f(int i,int j,vector<int>& nums){
    if(i>j)return 0;
    if(i==j)return nums[i];

    int choose_start_idx=nums[i] + min( f(i+2,j,nums) , f(i+1,j-1,nums) ) ;
    int choose_end_idx=nums[j] + min( f(i,j-2,nums) , f(i+1,j-1,nums) ) ;

    return max(choose_start_idx,choose_end_idx);
    
}
    bool predictTheWinner(vector<int>& nums){
        int bestOfPlayerA=f(0,nums.size()-1,nums);
        return bestOfPlayerA>=(accumulate(nums.begin(),nums.end(),0)-bestOfPlayerA);
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int n=nums.size();

        int five=0,ten=0;

        for(int i=0;i<n;i++){
            if(nums[i]==5){
                five++;
            }
            else if(nums[i]==10){
                if(five>=1){
                    ten++;
                    five--;
                }
                else return 0;
            }
            else{
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return 0;
            }
        }

        return 1;
    }
};
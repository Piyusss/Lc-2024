class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0 ; i<nums.size()-1 ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[j]<nums[i]){
                    int a=nums[i];
                    int b=nums[j];
                    nums[i]=b;
                    nums[j]=a;
                }
            }
        }
    }
};
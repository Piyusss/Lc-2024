class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();

        int pr=1;
        for(int i=0;i<n;i++)pr*=nums[i];

        vector<int>noOfZeros;
        int productWithoutZeros=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)noOfZeros.push_back(i);
            else productWithoutZeros*=nums[i];
        }
        if(pr){
            for(int i=0;i<n;i++)nums[i]=pr/nums[i];
            return nums;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0)nums[i]=0;
            else{
                if(noOfZeros.size()>1)nums[i]=0;
                else nums[i]=productWithoutZeros;
            }
        }
        return nums;
    }
};
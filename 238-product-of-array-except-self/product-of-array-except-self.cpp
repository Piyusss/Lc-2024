class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int>ans;
        int pr=1;
        for(int i=0;i<n;i++){
            pr*=nums[i];
        }
        //now
        vector<int>flag;
        int nzp=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)flag.push_back(i);
            if(nums[i]!=0)nzp*=nums[i];
        }
        if(pr!=0){
            for(int i=0;i<n;i++)nums[i]=pr/nums[i];
            return nums;
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    nums[i]=0;
                }
                else{
                    if(flag.size()>1)nums[i]=0;
                    else nums[i]=nzp;
                }
            }
            return nums;
        }
        return nums;
    }
};
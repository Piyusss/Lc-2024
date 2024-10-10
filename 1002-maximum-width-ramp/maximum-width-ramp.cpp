class Solution {
public:

    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>maxiFromRight(n);
        int maxi=0;

        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            maxiFromRight[i]=maxi;
        }

        int res=0;
        int i=0,j=1;
        
        while(j<n){
            if(nums[i]>maxiFromRight[j])i++;
            res=max(res,j-i);
            j++;
        }

        return res;

    }
};


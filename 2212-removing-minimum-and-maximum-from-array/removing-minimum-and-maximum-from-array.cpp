class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int minIdx=-1,maxIdx=-1,mini=INT_MAX,maxi=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minIdx=i;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxIdx=i;
            }
        }

        bool flag=maxIdx<minIdx,flag1=maxIdx==minIdx;

        if(flag) return min(maxIdx+1+n-minIdx,min(minIdx+1,n-maxIdx));
        return min(minIdx+1+n-maxIdx,min(maxIdx+1,n-minIdx));
    }
};
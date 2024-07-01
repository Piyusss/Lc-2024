class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int pr=1,pr2=1,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(pr>=1e9){
                pr=1;continue;
            }
            pr*=nums[i];
            maxi=max(maxi,pr);
            if(pr==0)pr=1;

            if(pr2>=1e9){
                pr2=1;continue;
            }
            pr2*=nums[n-i-1];
            maxi=max(maxi,pr2);
            if(pr2==0)pr2=1;
        }

        return maxi;
    }
};
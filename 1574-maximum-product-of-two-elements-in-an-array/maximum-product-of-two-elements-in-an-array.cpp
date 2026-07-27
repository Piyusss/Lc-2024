class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int m=0,sm=0;

        for(int i=0;i<n;i++){
            int d=nums[i]-1;

            if(d>m){
                sm=m;
                m=d;
            }
            else if(d>sm){
                sm=d;
            }

        }

        return m*sm;
    }
};
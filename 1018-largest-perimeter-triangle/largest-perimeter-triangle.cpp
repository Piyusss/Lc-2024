class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){

            int sideA=nums[i];
            int sideB=nums[i-1];
            int sideC=nums[i-2];

            int per=sideA+sideB+sideC;

            if(sideA+sideB>sideC && sideB+sideC>sideA && sideC+sideA>sideB) return per;
        }

        return 0x0;
    }
};
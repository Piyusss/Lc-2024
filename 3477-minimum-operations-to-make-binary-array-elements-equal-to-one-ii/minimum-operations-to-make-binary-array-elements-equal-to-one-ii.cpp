class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int flips=0;

        int curFlipCount=0;

        for(int i=0;i<n;i++){

            if(curFlipCount%2==nums[i]){

                flips++;
                curFlipCount++;
            }

        }   

        return flips;
    }
};
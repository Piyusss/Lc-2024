class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();

        int flips=0;

        int curFlipCount=0;

        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==6){
                curFlipCount--;
            }

            if(curFlipCount%2==nums[i]){
                if(i+k>n)return -1;

                nums[i]=6;
                flips++;
                curFlipCount++;
            }
        }   

        return flips;
    }
};
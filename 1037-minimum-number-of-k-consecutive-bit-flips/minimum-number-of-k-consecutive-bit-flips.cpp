class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();

        int flips=0;

        vector<int>isFlipped(n);

        int curFlipCount=0;

        for(int i=0;i<n;i++){
            if(i>=k && isFlipped[i-k]){
                curFlipCount--;
            }

            if(curFlipCount%2==nums[i]){
                if(i+k>n)return -1;

                isFlipped[i]=1;
                flips++;
                curFlipCount++;
            }
        }   

        return flips;
    }
};
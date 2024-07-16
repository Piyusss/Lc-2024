class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();

        int flips=0;

        int curFlipCount=0;

        deque<int>dq;

        for(int i=0;i<n;i++){
            if(i>=k){
                curFlipCount-=dq.front();
                dq.pop_front();
            }

            if(curFlipCount%2==nums[i]){
                if(i+k>n)return -1;

                dq.push_back(1);
                flips++;
                curFlipCount++;
            }
            else{
                dq.push_back(0);
            }
        }   

        return flips;
    }
};
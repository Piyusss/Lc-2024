class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>res;

        deque<int>dq;
        dq.push_back(0);

        //Handle for the first window
        for(int i=1;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        //Handle for the remaining windows
        for(int i=k;i<n;i++){
            //Eliminate all elements of previous window
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();

            //Place new element at pefect position
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);

            //Max element at front
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++){
            int el=nums[i];

            pq.push(el);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};
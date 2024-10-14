class Solution {
public:

#define ll long long

    int minStoneSum(vector<int>& nums, int k) {
        int n=nums.size();
        
        priority_queue<int,vector<int>>pq;

        for(auto &it:nums) pq.push(it);

        while(k--){
            auto it=pq.top();
            pq.pop();
            
            pq.push(it-(it/2));
        }

        int res=0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }

        return res;

    }
};
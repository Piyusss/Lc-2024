class Solution {
public:

#define ll long long

    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        
        priority_queue<int,vector<int>>pq;

        for(auto &it:nums) pq.push(it);

        ll res=0;

        while(k--){
            auto it=pq.top();
            pq.pop();

            res+=it;
            
            pq.push((it+3-1)/3);
        }

        return res;

    }
};
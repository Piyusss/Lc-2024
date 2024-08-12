class KthLargest {
public:
int k;       
priority_queue<int,vector<int>,greater<int>>pq2;

    KthLargest(int K, vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        k=K;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>K)pq.pop();
        }
        pq2=pq;

    }
    
    int add(int val) {
        pq2.push(val);
        if(pq2.size()>k)pq2.pop();
        return pq2.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
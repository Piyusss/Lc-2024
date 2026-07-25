class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &c:s){
            pq.push(c-'0');
            if(pq.size()>2) pq.pop();
        }

        int maxi=pq.top();
        pq.pop();
        int secondMaxi=pq.top();

        return maxi*secondMaxi;
    }
};
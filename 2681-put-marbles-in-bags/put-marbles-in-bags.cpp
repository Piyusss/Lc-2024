class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long n=weights.size();
        vector<long long>store;
        for(long long i=0;i<n-1;i++){
            store.push_back(weights[i]+weights[i+1]);
        }
        sort(store.begin(),store.end());
        long long frontSum=0,backSum=0;
        for(long long i=0;i<k-1;i++){
            frontSum+=store[i];
            backSum+=store[n-i-2];
        }
        return backSum-frontSum;
    }
};
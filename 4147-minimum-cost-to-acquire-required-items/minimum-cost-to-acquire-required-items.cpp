using ll=long long;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll x=1LL*min(need1,need2);
        return x*min(costBoth,cost1+cost2) + (need1-x)*min(cost1,costBoth) + (need2-x)*min(cost2,costBoth);
    }
};
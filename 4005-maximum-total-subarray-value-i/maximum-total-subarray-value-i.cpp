class Solution {
public:
    long long maxTotalValue(vector<int>& v, int k) {
        return 1LL*(*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end()))*k;
    }
};
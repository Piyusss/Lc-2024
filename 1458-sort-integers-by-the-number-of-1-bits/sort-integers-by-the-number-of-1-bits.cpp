class Solution {
public:

static bool comp(const int a, const int b){
    int one=__builtin_popcount(a);
    int two=__builtin_popcount(b);
    
    if(one==two)return a<b;
    return one<two;
}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
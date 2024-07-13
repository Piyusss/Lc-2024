class Solution {
public:

static int f(int x){
    int cnt=0;int fix=32;
    while(fix--){
        cnt+=x & 1;
        x=x>>1;
    }
    return cnt;
}

static bool comp(const int a, const int b){
    int one=f(a);
    int two=f(b);
    
    if(one==two)return a<b;
    return one<two;
}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
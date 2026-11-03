class Solution {
public:
    int minMoves(vector<int>& a) {
        int n=a.size(),mx=a[0],s=0;

        for(auto &x:a){
            mx=max(mx,x);
            s+=x;
        }

        return n*mx-s;
    }
};
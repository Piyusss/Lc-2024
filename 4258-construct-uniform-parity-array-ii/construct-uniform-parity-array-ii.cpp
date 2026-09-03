class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int x=INT_MAX;

        for(auto &i:a) if(i&1) x=min(x,i);
        if(x==INT_MAX) return 1;

        for(auto &i:a) if(i<x) return 0;
        return 1;
    }
};
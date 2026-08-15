class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n=a.size();

        int x=0;
        bool f=0;

        for(auto &y:a){
            x^=y;
            if(y) f=1;
        }

        return x?n:f?n-1:0;
    }
};
class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size(),cnt=0;

        for(int i=0;i<n;i++) cnt+=('z'-s[i]+1)*(i+1);
        return cnt;
    }
};
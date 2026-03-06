class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();

        for(int i=0;i<n-1;i++) if(s[i]=='0' && s[i+1]=='1') return 0;
        return 1;
    }
};
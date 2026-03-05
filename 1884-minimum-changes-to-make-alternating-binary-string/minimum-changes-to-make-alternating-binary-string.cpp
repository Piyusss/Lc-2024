class Solution {
public:
    int minOperations(string s) {
        int m=0;

        for(int i=0;i<s.size();i++) if((s[i]-'0')!=(i&1)) m++;
        return min(m,(int)s.size()-m);
    }
};
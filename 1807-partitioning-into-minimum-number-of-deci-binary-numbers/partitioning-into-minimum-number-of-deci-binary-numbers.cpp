class Solution {
public:
    int minPartitions(string n) {
        int res=0;

        for(auto &c:n) if((c-'0')>res) res=(c-'0');
        return res;
    }
};
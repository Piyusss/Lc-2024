class Solution {
public:
    bool stoneGameIX(vector<int>&a){
        vector<int>c(3);
        for(auto &x:a) c[x%3]+=1;

        if(c[0]%2==0) return c[1]&&c[2];
        return abs(c[1]-c[2])>2;
    }
};
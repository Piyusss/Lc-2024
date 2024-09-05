class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int rem=mean*(n+m)-accumulate(rolls.begin(),rolls.end(),0);

        if(rem>n*6 || rem<n*1)return {};
        
        vector<int>res(n,rem/n);
        for(int i=0;i<rem%n;i++)res[i]++;

        return res;
    }
};
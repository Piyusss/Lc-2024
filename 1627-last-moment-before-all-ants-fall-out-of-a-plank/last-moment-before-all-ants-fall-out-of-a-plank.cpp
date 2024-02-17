class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mini=1e8;
        int maxi=0;

        for(auto it:left){
            maxi=max(maxi,it);
        }
        for(auto it:right){
            mini=min(mini,it);
        }
        return max(maxi,n-mini);
    }
};
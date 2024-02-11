class Solution {
public:

    int findLongestChain(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int>next(n+1,0),cur(n+1,0);
       //now
       for(int ind=n-1;ind>=0;ind--){
           for(int prevInd=ind-1;prevInd>=-1;prevInd--){
               int len=0+next[prevInd+1];
                    if(prevInd==-1 || v[ind][0]>v[prevInd][1]){
                        len=max(len, 1+next[ind+1]);
                    }
                cur[prevInd+1]=len;
           }
           next=cur;
       }
       return next[0];
    }
};
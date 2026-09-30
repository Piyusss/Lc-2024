class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int d=0;
        vector<int>ans;

        for(auto &c:s){
            if(c=='('){
                d++;
                ans.push_back(d%2);
            }
            else{
                ans.push_back(d%2);
                d--;
            }
        }

        return ans;
    }
};
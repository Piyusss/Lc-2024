class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int d=0;

        for(auto &c:s){
            if(c=='('){
                if(d) ans+=c;
                d++;
            }
            else{
                d--;
                if(d) ans+=c;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        int x=0,b=0,p=0;

        for(auto &c:s){
            if(c=='('){
                b++;
                p=1;
            }
            else{
                b--;
                x+=p<<b;
                p=0;
            }
        }

        return x;
    }
};
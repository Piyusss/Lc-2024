class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(auto &c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(c==')'){
                    if(!st.empty() && st.top()=='(') st.pop();
                    else return 0;
                }
                else if(c=='}'){
                    if(!st.empty() && st.top()=='{') st.pop();
                    else return 0;
                }
                else{
                    if(!st.empty() && st.top()=='[') st.pop();
                    else return 0;
                }
            }
        }

        return st.empty();
    }
};
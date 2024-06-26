class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int>st;
        //now
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(!st.empty() && st.top()=='('){
                        st.pop();
                    }
                    else return 0;
                }
                if(s[i]=='}'){
                    if(!st.empty() && st.top()=='{'){
                        st.pop();
                    }
                    else return 0;
                }
                if(s[i]==']'){
                    if(!st.empty() && st.top()=='['){
                        st.pop();
                    }
                    else return 0;
                }
            }
        }
        if(!st.empty())return 0;
        return 1;
    }
};
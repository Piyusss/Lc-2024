class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();

        stack<int>st;

        string temp="";

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(temp.size());
            }
            else if(s[i]!=')'){
                temp+=s[i];
            }
            else{
                int idx=st.top();
                reverse(temp.begin()+idx,temp.end());
                st.pop();
            }
        }
        return temp;
    }
};
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> st;
    void operation(string& op){
        if (st.empty()) return;
        int n2=st.back();
        st.pop_back();
        if (st.empty()) return;
        int n1=st.back();
        st.pop_back();
        int x;
        switch(op[0]){
            case '+': x=n1+n2; break;
            case '-': x=n1-n2; break;
            case '*': x=n1*n2; break;
            case '/': x=n1/n2; break;
        }
        st.push_back(x);
    }
    int evalRPN(vector<string>& tokens) {
        for(string& s: tokens){
            if (s.size()>1 || isdigit(s[0])){
                int x=stoi(s);
                st.push_back(x);
            }
            else operation(s);      
        }
        if (st.empty()) return 0;
        return st.back();
    }
};
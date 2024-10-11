class Solution {
public:

vector<string>res;
int n;

bool check(string s){
    stack<char>st;

    for(auto &it:s){
        if(it=='(')st.push('(');
        else{
            if(!st.empty())st.pop();
            else return 0;
        }
    }
    return st.size()==0;
}

void f(string s){
    if(s.size()==2*n){
        if(check(s))res.push_back(s);
        return;
    }

    s+='(';
    f(s);
    s.pop_back();

    s+=')';
    f(s);
    s.pop_back();
}

    vector<string> generateParenthesis(int N){
        n=N;
        string s="";
        
        f(s);

        return res;
    }
};
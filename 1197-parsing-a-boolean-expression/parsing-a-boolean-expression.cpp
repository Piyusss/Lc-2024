class Solution {
public:

char f(vector<char>&store,char op){
    if(op=='!') return *store.begin()=='t' ? 'f' : 't';

    if(op=='&'){
        for(auto &it:store) if(it=='f') return 'f';
        return 't';
    }
    if(op=='|'){
        for(auto &it:store) if(it=='t') return 't';
        return 'f';
    }

    return '^';
}
    bool parseBoolExpr(string s){
        stack<char>st;
        vector<char>store;

        for(auto &it:s){
            if(it!=')' && it!=',') st.push(it);

            if(it==')'){
                store.clear();
                while(!st.empty() && st.top()!='('){
                    store.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(f(store,op));
            }
        }

        return st.top() == 't' ? 1 : 0 ;

    }
};
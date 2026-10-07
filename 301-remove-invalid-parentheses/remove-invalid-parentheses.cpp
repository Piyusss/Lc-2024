class Solution {
public:

    bool f(string &s){
        int x=0;

        for(auto &c:s){
            if(c=='(') x++;
            else if(c==')'){
                if(--x<0) return 0;
            }
        }

        return !x;
    }

    void g(int i,string&s,string&t,int &mx,set<string>&a){
        if(t.size()+s.size()-i<mx) return;

        if(i==s.size()){
            if(f(t)){
                if(t.size()>mx){
                    mx=t.size();
                    a.clear();
                    a.insert(t);
                }else if(t.size()==mx) a.insert(t);
            }
            return;
        }

        t+=s[i];
        g(i+1,s,t,mx,a);
        t.pop_back();

        if(s[i]=='('||s[i]==')') g(i+1,s,t,mx,a);
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string>a;
        string t;

        int mx=0;
        g(0,s,t,mx,a);

        return vector<string>(a.begin(),a.end());
    }
};
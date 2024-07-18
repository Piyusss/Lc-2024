class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();

        stack<int>st;
        vector<int>wormhole(n);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int idx=st.top();
                st.pop();
                wormhole[idx]=i;
                wormhole[i]=idx;
            }
        }

        string temp="";
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=wormhole[i];
                flag=-flag;
            }
            else{
                temp+=s[i];
            }
        }

        return temp;
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        stack<char>st;

        int cnt=0;
        
        for(int i=0;i<n;i++){
            st.push(s[i]);

            if(s[i]=='b')continue;
            else{
                while(!st.empty() && st.top()!='b')st.pop();
                if(!st.empty()){cnt++;st.pop();continue;}
            }
        }

        return cnt;
    }
};
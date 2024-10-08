class Solution {
public:
    int minSwaps(string s){
        stack<char>st;

        for(auto &it:s){
            if(it=='[')st.push('[');
            else if(!st.empty())st.pop();
        }

        return (st.size()+1)/2;
    }
};
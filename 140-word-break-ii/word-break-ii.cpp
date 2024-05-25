class Solution {
public:

vector<string>ans;
unordered_set<string>st;
string curSent="";

void f(int idx,string s){
    if(idx>=s.size()){
        ans.push_back(curSent);
        return;
    }

    for(int i=idx;i<s.size();i++){
        string temp=s.substr(idx,i-idx+1);
        if(st.count(temp)){
            string storeCurSent=curSent;
            if(!curSent.empty())curSent+=" ";
            curSent+=temp;
            f(i+1,s);
            curSent=storeCurSent;
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(),wordDict.end());
        f(0,s);
        return ans;
    }
};
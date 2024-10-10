class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();

        unordered_set<string>st,res;

        for(int i=0;i<=n-10;i++){
            string ext=s.substr(i,10);
            if(st.find(ext)!=st.end()) res.insert(ext);
            else st.insert(ext);
        }

        return {res.begin(),res.end()};
    }
};
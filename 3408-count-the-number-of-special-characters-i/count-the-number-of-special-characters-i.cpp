class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        vector<int>lo(26),up(26);

        set<char>st;
        for(auto &it:word)st.insert(it);

        vector<char>v;
        for(auto &it:st)v.push_back(it);

        for(auto &it:v){
            if((it>=97) && it<=122) lo[it-'a']++;
            else up[it-'A']++;
        }
        
        for(int i=0;i<26;i++) ans+=min(lo[i],up[i]);
        return ans;
    }
};
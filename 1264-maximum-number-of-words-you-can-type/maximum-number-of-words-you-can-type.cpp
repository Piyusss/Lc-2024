class Solution {
public:

    bool f(string &s,unordered_map<char,int>&mp){
        for(auto &c:s) if(mp[c]) return 0;
        return 1;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mp;

        for(auto &c:brokenLetters) mp[c]++;
        int cnt=0;
        
        string w;
        stringstream ss(text);
        while(ss>>w) if(f(w,mp)) cnt++;

        return cnt;
    }
};
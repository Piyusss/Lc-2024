class Solution {
public:

int k;

int f(string s){
    if(s=="") return 0;

    unordered_map<char,int>mp;
    for(auto &c:s) mp[c]++;

    for(int i=0;i<s.size();i++) {
        if(mp[s[i]]<k) {
            int l=f(s.substr(0,i));
            int r=f(s.substr(i+1));
            return max(l,r);
        }
    }

    return s.size();
}

    int longestSubstring(string s, int K){
        k=K;
        return f(s);
    }
};
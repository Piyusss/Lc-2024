class Solution {
public:
    bool f(int x){
        string s=to_string(x);
        vector<int>v(10);

        for(auto &it:s) v[it-'0']++;

        for(auto &it:s){
            int c=it-'0';
            if(c==0 || v[c]!=c) return 0;
        }

        return 1;
    }

    int nextBeautifulNumber(int n) {
        for(int i=n+1; ;i++) if(f(i)) return i;
    }
};
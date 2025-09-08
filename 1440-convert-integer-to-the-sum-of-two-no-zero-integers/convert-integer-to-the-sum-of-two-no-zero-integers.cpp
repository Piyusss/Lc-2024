class Solution {
public:

    bool f(int x){
        string s=to_string(x);
        int n=s.size();

        for(int i=0;i<n;i++) if(s[i]=='0') return 0;
        return 1;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            int a=i;
            int b=n-i;
            if(f(a) && f(b)) return {a,b};
        }

        return {};
    }
};
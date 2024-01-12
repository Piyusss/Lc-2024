class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int cnt1=0;
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                if(i<n/2)cnt1++;
                else cnt1--;
            }
        }
        //now
        if(cnt1==0)return 1;
        return 0;

    }
};
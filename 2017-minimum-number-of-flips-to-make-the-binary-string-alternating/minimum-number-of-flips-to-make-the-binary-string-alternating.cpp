class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),a=0,b=0;

        for(int i=0;i<n;i++){
            if(i%2 == (s[i]-'0')) b++;
            else a++;
        }

        int r=min(a,b);
        s+=s;

        for(int i=n;i<2*n;i++){
            int j=i-n;

            if(j%2 != (s[j]-'0')) a--;
            else b--;

            if(i%2 == (s[i]-'0')) b++;
            else a++;

            r=min(r,min(a,b));
        }

        return r;
    }
};
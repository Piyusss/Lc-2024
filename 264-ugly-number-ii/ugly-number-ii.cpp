class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n+1,0);
        int i2=1,i3=1,i5=1;

        v[1]=1;

        for(int i=2;i<=n;i++){
            int i2ThUgly=v[i2]*2;
            int i3ThUgly=v[i3]*3;
            int i5ThUgly=v[i5]*5;

            int mini=min({i2ThUgly,i3ThUgly,i5ThUgly});
            v[i]=mini;

            if(mini==i2ThUgly)i2++;
            if(mini==i3ThUgly)i3++;
            if(mini==i5ThUgly)i5++;
        }

        return v[n];
    }
};
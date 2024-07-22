class Solution {
public:
#define ll long long
    int myAtoi(string s) {
        ll n=s.size();

        ll start=0;ll sign=1;ll res=0;
        while(start<n &&  s[start]==' ')start++;

        if(start<n && s[start]=='-'){sign=-1;start++;}
        else if(start<n && s[start]=='+'){sign=1;start++;}


        while(start<n && ( s[start]>='0' && s[start]<='9' )  ){
            res=(res*10) + (s[start]-'0');
            if(res>INT_MAX)return sign==1 ? INT_MAX : INT_MIN;
            start++;
        }

        if(sign==-1)res=-res;

        if(res>(long long)INT_MAX)return INT_MAX;
        else if(res<(long long)INT_MIN)return INT_MIN;

        return (int)res;
    }
};
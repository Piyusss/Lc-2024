class Solution {
public:

#define ll long long
string f2(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll f(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

    int bitwiseComplement(int n) {
        if(n==0)return 1;

        string s=f2(n);
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }
        return f(s);
    }
};
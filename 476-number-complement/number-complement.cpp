class Solution {
public:

#define ll __int128_t
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;__int128_t dec_value = 0;__int128_t base = 1;__int128_t len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

    int findComplement(int n) {
        if(n==0)return 1;

        __int128_t nn=n;
        string s=decToBinary(nn);
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }
        return binaryToDecimal(s);
    }
};
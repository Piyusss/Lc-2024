class Solution {
public:
    string getHappyString(int n,int k) {
        int tot=3<<(n-1);
        if(k>tot) return "";

        k--;
        string r(n,' ');
        r[0]='a'+(k>>(n-1));

        char op[3][2]={{'b','c'},{'a','c'},{'a','b'}};

        for(int i=1;i<n;i++){
            int b=(k>>(n-1-i))&1;
            r[i]=op[r[i-1]-'a'][b];
        }

        return r;
    }
};
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string a=to_string(num1);
        string b=to_string(num2);
        string c=to_string(num3);

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        reverse(c.begin(),c.end());

        int times=4-a.size();
        for(int i=0;i<times;i++)a+="0";
        reverse(a.begin(),a.end());

        times=4-b.size();
        for(int i=0;i<times;i++)b+="0";
        reverse(b.begin(),b.end());

        times=4-c.size();
        for(int i=0;i<times;i++)c+="0";
        reverse(c.begin(),c.end());

        string ans="";
        cout<<a<<" "<<b<<" "<<c;

        for(int i=0;i<4;i++)ans+=min(a[i],min(b[i],c[i]));

        return stoi(ans);
    }
};
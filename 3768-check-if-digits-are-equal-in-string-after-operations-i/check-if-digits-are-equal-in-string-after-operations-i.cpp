class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();

        string temp="";

        while(s.size()!=2){
            for(int i=0;i<=s.size()-2;i++){
                char s1=s[i];
                char s2=s[i+1];

                int num=((s1-'0')+(s2-'0')) % 10;
                temp += to_string(num);
            }
            s=temp;
            temp="";
        }

        return s[0]==s[1];
    }
};
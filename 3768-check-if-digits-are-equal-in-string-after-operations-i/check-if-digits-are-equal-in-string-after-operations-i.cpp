class Solution {
public:
    bool hasSameDigits(string s) {
        string temp="";

        while(s.size()!=2){
            for(int i=0;i<=s.size()-2;i++){
                temp += to_string(((s[i]-'0')+(s[i+1]-'0')) % 10);
            }
            s=temp;
            temp="";
        }

        return s[0]==s[1];
    }
};
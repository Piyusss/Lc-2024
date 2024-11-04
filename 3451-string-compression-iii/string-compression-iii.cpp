class Solution {
public:
    string compressedString(string s){
        int n=s.size();

        string res="";
        int cnt=1;

        for(int i=0;i<n-1;i++){
            if(cnt==9 || s[i]!=s[i+1]){
                res += to_string(cnt);
                res += s[i];
                cnt=1;
            }
            else cnt++;
        }

        return res + to_string(cnt) + s[n-1];
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        //now
        int flag=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){flag=i;break;}
        }
        //now
        int ans=0;
        for(int i=flag;i>=0;i--){
            if(s[i]!=' ')ans++;
            else break;
        }
        return ans;
    }
};
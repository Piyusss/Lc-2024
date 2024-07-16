class Solution {
public:

    bool isPal(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }

    bool validPalindrome(string s) {
        int n=s.size();

        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(isPal(s,i+1,j) || isPal(s,i,j-1))return 1;
                return 0;
            }
            i++;j--;
        }

        return 1;
    }
};
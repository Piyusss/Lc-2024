class Solution {
public:
bool isPal(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])return 0;
        i++;j--;
    }
    return 1;
}
    string longestPalindrome(string s) {
        int n=s.size();int start=0;int max_len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i+1)>max_len && isPal(s,i,j)){
                    max_len=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,max_len);
    }
};
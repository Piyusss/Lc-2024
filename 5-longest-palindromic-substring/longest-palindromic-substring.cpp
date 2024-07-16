class Solution {
public:

bool isPal(string &s,int i,int j){
    if(i>=j)return 1;

    if(s[i]==s[j])return isPal(s,i+1,j-1);
    return 0;
}
    string longestPalindrome(string s) {
        int n=s.size();
        
        int max_len=0;
        int sp=0;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j)){
                    if(max_len<j-i+1){
                        max_len=j-i+1;
                        sp=i;
                    }
                }
            }
         }
         return s.substr(sp,max_len);
    }
};
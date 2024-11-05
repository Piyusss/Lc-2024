class Solution {
public:
    int minChanges(string s){
        int n=s.size();

        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                cnt+=1;
                s[i+1]=s[i];
            }
            i+=1;
        }

        return cnt;

    }
};
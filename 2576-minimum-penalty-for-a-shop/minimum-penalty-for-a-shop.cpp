class Solution {
public:
    int bestClosingTime(string s) {
        int p=0;
        for(auto &c:s)if(c=='Y')p++;

        int b=p,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='Y')p--;
            else p++;
            
            if(p<b){
                b=p;
                r=i+1;
            }
        }

        return r;
    }
};
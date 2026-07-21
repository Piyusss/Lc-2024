class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one=0;
        for(auto &c:s)if(c=='1')one+=1;
        
        string t='1'+s+'1';
        int m=t.length(),res=one;
        
        for(int i=1;i<=m-2;){
            if(t[i] == '1'){
                int start=i;
                while(i<m-1 && t[i]=='1')i+=1;
                int end=i-1;
                
                if(t[start-1]=='0' && t[end+1]=='0'){
                    int l=0,pos=start-1;
                    while(pos>=0 && t[pos]=='0'){
                        l+=1;
                        pos-=1;
                    }
                    int r=0;
                    pos=end+1;
                    while(pos<m && t[pos]=='0'){
                        r+=1;
                        pos+=1;
                    }
                    res=max(res,one+l+r);
                }
            }
            else i+=1;
        }

        return res;
    }
};
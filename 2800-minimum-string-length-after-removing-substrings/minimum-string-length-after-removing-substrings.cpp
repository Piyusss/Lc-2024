class Solution {
public:
    int minLength(string s) {
        int n=s.size();

        while(1){
            int idx=s.find("AB"),idx2=s.find("CD"),flag=0;
            if(idx!=-1) s.erase(idx,2),flag=1;
            else if(idx2!=-1) s.erase(idx2,2),flag=1;
            if(!flag)break;
        }

        cout<<s;
        return s.size();
    }
};
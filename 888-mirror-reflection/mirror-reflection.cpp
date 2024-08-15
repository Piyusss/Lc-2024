class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p==q)return 1;

        while(!(p&1) && !(q&1)){
            p=p>>1;
            q=q>>1;
        }

        if((p&1) && (q&1))return 1;
        if((p&1) && !(q&1))return 0;
        if(!(p&1) && (q&1))return 2;

        return -1;
    }
};
class Solution {
public:
    int reverseBits(int n) {
        unsigned int r=0;
        
        for(int i=0;i<32;i++){
            r<<=1;
            r|=(n&1);
            n>>=1;
        }
        
        return r;
    }
};
class Solution {
public:
    int addDigits(int num){
        if(num<=9)return num;
        while(num/10){
            int cur=num;
            num=0;
            while(cur){
                num+=(cur%10);
                cur/=10;
            }
        }
        return num;
    }
};
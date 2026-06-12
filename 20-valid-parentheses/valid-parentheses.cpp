class Solution {
public:
    bool isValid(string s) {
        int inc=0;

        for(auto &c:s){
            if(c=='(' || c=='{' || c=='['){
                s[inc]=c;
                inc+=1;
            }
            else{
                if(inc==0) return 0;
                
                inc-=1;
                char ch=s[inc];

                if((c==')' && ch!='(') || (c=='}' && ch!='{') || (c==']' && ch!='[')) return 0;
            }
        }

        return !inc;
    }
};
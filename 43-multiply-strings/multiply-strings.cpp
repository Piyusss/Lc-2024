class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int n1=num1.size();
        int n2=num2.size();

        vector<int>res(n1+n2,0);

        for(int j=n2-1;j>=0;j--){
            for(int i=n1-1;i>=0;i--){
                res[i+j+1]+=(num2[j]-'0')*(num1[i]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]=res[i+j+1]%10;
            }
        }
        
        string ans="";
        int mark=-1;
        
        for(int i=0;i<res.size();i++){
           if(res[i]!=0){
            mark=i;
            break;
           }
        }

        for(int i=mark;i<res.size();i++)ans+=to_string(res[i]);

        return ans;
    }
};
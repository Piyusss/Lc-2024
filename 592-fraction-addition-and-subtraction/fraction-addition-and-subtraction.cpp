class Solution {
public:
    string fractionAddition(string expr){
        int n=expr.length();
        int nume=0,deno=1;

        int i=0;
        while(i<n){
            int currNume=0,currDeno=0;
            bool isNeg=(expr[i]=='-');
            if(expr[i]=='+' || expr[i]=='-')i++;

            while(i<n && isdigit(expr[i])){
                currNume=(currNume*10)+expr[i]-'0';
                i++;
            }
            i++;

            if(isNeg)currNume*=-1;

            while(i<n && isdigit(expr[i])){
                currDeno=(currDeno*10)+expr[i]-'0';
                i++;
            }

            nume=nume*currDeno+currNume*deno;
            deno=deno*currDeno;
        }

        return to_string(nume/abs(__gcd(nume,deno))) + "/" + to_string(deno/abs(__gcd(nume,deno)));
    }
};
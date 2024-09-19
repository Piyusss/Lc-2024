class Solution {
public:

vector<int>f(string exp){
    int n=exp.size();
    vector<int>res;

    for(int i=0;i<n;i++){
        if(!isdigit(exp[i])){
            vector<int>left=f(exp.substr(0,i));
            vector<int>right=f(exp.substr(i+1,n-1));

            for(auto &l:left){
                for(auto &r:right){
                    int val= exp[i]=='+' ? l+r : (exp[i]=='-' ? l-r : (exp[i]=='*' ? l*r : (0==0)));
                    res.push_back(val);
                }
            }
        }
    }

    if(res.empty()) res.push_back(stoi(exp));
    return res;
}
    vector<int> diffWaysToCompute(string exp) {
        return f(exp); 
    }
};
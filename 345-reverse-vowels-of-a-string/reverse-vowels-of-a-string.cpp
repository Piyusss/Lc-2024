class Solution {
public:
bool f(char ch){
    vector<char>v={'a','e','i','o','u',
                   'A','E','I','O','U'};
    if(find(v.begin(),v.end(),ch)!=v.end())return 1;
    return 0;
}
    string reverseVowels(string s) {
        int n=s.size();
        int i=0;int j=n-1;
        while(i<j){
            if(!f(s[i]) && !f(s[j])){
                i++;
                j--;
            }
            else if(f(s[i]) && f(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(f(s[i])){
                while(!f(s[j]))j--;
            }
            else {
                while(!f(s[i]))i++;
            }
        }
        return s;
    }
};
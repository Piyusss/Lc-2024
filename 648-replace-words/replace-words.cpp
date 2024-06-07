class Solution {
public:
string f(unordered_set<string>st,string word){
    for(int i=0;i<word.size();i++){
        string temp=word.substr(0,i);
        if(st.count(temp)){
            return temp;
        }
    }
    return word;
}
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string>st(dict.begin(),dict.end());
        string result="";

        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' ')){
            result+=f(st,word)+" ";
        }
        result.pop_back();
        return result;
    }
};
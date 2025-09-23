class Solution {
public:
vector<string>f(string s){
    vector<string>ans;
    stringstream ss(s);
    string temp="";

    while(getline(ss,temp,'.'))ans.push_back(temp);
    return ans;
}
    int compareVersion(string version1, string version2) {
        vector<string>tokens1=f(version1);
        vector<string>tokens2=f(version2);

        int i=0;
        while(i<tokens1.size() || i<tokens2.size()){
            int a=i<tokens1.size()?stoi(tokens1[i]):0;
            int b=i<tokens2.size()?stoi(tokens2[i]):0;

            if(a<b)return -1;
            else if(a>b)return 1;
            else i++;
        }
        return 0;
    }
};
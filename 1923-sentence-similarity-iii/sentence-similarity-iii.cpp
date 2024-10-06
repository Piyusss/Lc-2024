class Solution {
public:

    bool areSentencesSimilar(string a, string b) {
        if(a.size()<b.size()) swap(a,b);

        vector<string>v1,v2;

        stringstream ss1(a);
        string token;
        while(ss1>>token) v1.push_back(token);

        stringstream ss2(b);
        while(ss2>>token) v2.push_back(token);

        int n1=v1.size();
        int n2=v2.size();

        int i=0,j=n1-1,k=0,l=n2-1;

        while(i<n1 && k<n2 && v1[i]==v2[k]) i++, k++;
        while(j>=0 && l>=0 && v1[j]==v2[l]) j--,l--;

        return l<k;

    }
};
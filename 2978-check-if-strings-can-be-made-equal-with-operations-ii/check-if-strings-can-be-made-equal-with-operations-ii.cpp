class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return 0;

        int n=s1.size();
        vector<int>e1(26),o1(26),e2(26),o2(26);

        for(int i=0;i<n;i++){
            if(i%2==0){
                e1[s1[i]-'a']++;
                e2[s2[i]-'a']++;
            }
            else{
                o1[s1[i]-'a']++;
                o2[s2[i]-'a']++;
            }
        }

        return (e1==e2)&&(o1==o2);
    }
};
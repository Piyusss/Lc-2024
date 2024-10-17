class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();

        vector<int>v(n,n-1);

        for(int i=n-2;i>=0;i--) v[i] = s[i] > s[v[i+1]] ? i : v[i+1];

        for(int i=0;i<n;i++){
            if(i != v[i] && s[i] != s[v[i]]){
                swap(s[i],s[v[i]]);
                break;
            }
        }

        return stoi(s);

    }
};
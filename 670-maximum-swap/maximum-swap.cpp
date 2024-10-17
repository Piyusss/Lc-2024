class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();

        vector<int>v(n,-1);
        v[n-1]=n-1;

        for(int i=n-2;i>=0;i--){
            v[i] = s[i] > s[v[i+1]] ? i : v[i+1];
        }

        for(auto &it:v) cout<<it<<" ";

        for(int i=0;i<n;i++){
            if(i != v[i] && s[i] != s[v[i]]){
                swap(s[i],s[v[i]]);
                break;
            }
        }

        return stoi(s);

    }
};
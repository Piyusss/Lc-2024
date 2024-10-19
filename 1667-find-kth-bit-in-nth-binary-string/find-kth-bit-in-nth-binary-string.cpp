class Solution {
public:

string f(string s){
    for(auto &it:s) it=='0' ? it='1' : it='0';
    reverse(s.begin(),s.end());
    return s;
}
    char findKthBit(int n, int k){
        vector<string>bits(n,"0");
        for(int i=1;i<n;i++){
            bits[i] = bits[i-1] + "1" + f(bits[i-1]);
        }
        return bits[n-1][k-1];
    }
};
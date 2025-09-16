using ll=long long;

class Solution {
public:

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>st;

        for(auto &c:nums){
            while(!st.empty()){
                int top=st.back();
                int g=gcd(top,c);

                if(g==1) break;

                st.pop_back();
                ll merged=(ll)top/g*c;
                c=(int)merged;
            }
            st.push_back(c);
        }

        return st;
    }
};
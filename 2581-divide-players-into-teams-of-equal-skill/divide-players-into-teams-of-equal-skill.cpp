class Solution {
public:

#define ll long long
    long long dividePlayers(vector<int>& skill) {
        ll n=skill.size();

        sort(skill.begin(),skill.end());

        ll sum=skill[0]*skill[n-1];
        ll req=skill[0]+skill[n-1];
        ll i=1,j=n-2;

        while(i<j){
            if(skill[i]+skill[j]!=req)return -1;
            sum+=skill[i]*skill[j];
            i++,j--;
        }

        return (ll)sum;
    }
};
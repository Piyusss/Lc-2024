class Solution {
public:

string f(string s,vector<int>& mapping){
    int n=s.size();
    string ret="";
    for(int i=0;i<n;i++){
        int num=mapping[s[i]-'0'];
        ret+= to_string(num);
    }
    return ret;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();

        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            string have_to_convert=to_string(nums[i]);
            string mapped_str=f(have_to_convert,mapping);
            int num=stoi(mapped_str);

            v.push_back({num,i});


        }

        vector<int>ans;
        sort(v.begin(),v.end());
        for(auto it:v){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};
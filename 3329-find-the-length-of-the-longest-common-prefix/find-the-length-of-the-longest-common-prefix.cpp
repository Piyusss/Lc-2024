class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        string flag="";

        unordered_map<int,int>mp1;
        for(int i=0;i<n;i++){
            string s=to_string(arr1[i]);
            for(int j=1;j<=s.size();j++){
                flag=s.substr(0,j);
                mp1[stoi(flag)]++;
            }
        }

        int maxi=0;
        for(int i=0;i<m;i++){
            string s=to_string(arr2[i]);
            for(int j=1;j<=s.size();j++){
                flag=s.substr(0,j);
                if(mp1.find(stoi(flag))!=mp1.end())maxi=max(maxi,(int)flag.size());
            }
        }

        return maxi;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();

        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
            if(mp[it]>(n+1)/2)return "";
        }

        //always-possible

        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        for(auto &it:mp) pq.push({it.second,it.first});

        string res="";

        while(pq.size()>1){
            auto p1=pq.top();
            pq.pop();

            auto p2=pq.top();
            pq.pop();

            res+=p1.second;
            res+=p2.second;
            p1.first--;
            p2.first--;

            if(p1.first>0)pq.push(p1);
            if(p2.first>0)pq.push(p2);

        }

        if(!pq.empty()) res+=pq.top().second;

        return res;

    }
};
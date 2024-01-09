class Solution {
public:
    int minMutation(string start, string end,vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>vis;

        queue<string>q;
        q.push(start);
        vis.insert(start);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                if(curr==end)return level;
                q.pop();

                for(char ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string mut=curr;
                        mut[i]=ch;

                        if(vis.find(mut)==vis.end()
                        && bankset.find(mut)!=bankset.end()){
                            vis.insert(mut);
                            q.push(mut);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
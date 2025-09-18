#define ll long long

class TaskManager {

    unordered_map<int,pair<int,int>> m;
    priority_queue<pair<int,int>> q;

public:
    TaskManager(vector<vector<int>>& v) {
        for(int i=0;i<v.size();i++){
            int u=v[i][0],t=v[i][1],p=v[i][2];
            m[t]={u,p};
            q.push({p,t});
        }
    }

    void add(int u,int t,int p){
        m[t]={u,p};
        q.push({p,t});
    }

    void edit(int t,int p){
        m[t].second=p;
        q.push({p,t});
    }

    void rmv(int t){
        m.erase(t);
    }

    int execTop(){
        while(!q.empty()){
            int p=q.top().first,t=q.top().second;
            q.pop();
            if(m.count(t)&&m[t].second==p){
                int u=m[t].first;
                m.erase(t);
                return u;
            }
        }

        return -1;
    }

};
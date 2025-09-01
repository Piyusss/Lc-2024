class Solution{
public:

    static double f(int p,int t){
        return (double)(p+1)/(t+1)-(double)p/t;
    }

    double maxAverageRatio(vector<vector<int>>& c,int e){
        priority_queue<array<double,3>>h;

        for(auto &x:c){
            int p=x[0],t=x[1];
            h.push({f(p,t),(double)p,(double)t});
        }

        while(e--){
            auto a=h.top();h.pop();
            double p=a[1]+1,t=a[2]+1;
            h.push({f((int)p,(int)t),p,t});
        }

        double s=0.0;
        while(!h.empty()){
            auto a=h.top();h.pop();
            s+=a[1]/a[2];
        }

        return s/c.size();
    }
};
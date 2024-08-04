class BrowserHistory {
public:

stack<string>past,future;
string cur;
    BrowserHistory(string homepage) {
        cur=homepage;
    }
    
    void visit(string url) {
        past.push(cur);
        cur=url;
        while(future.size()>0)future.pop();
    }
    
    string back(int steps) {
        while(steps>0 && !past.empty()){
            future.push(cur);
            cur=past.top();
            past.pop();
            steps--;
        }
        return cur;
    }
    
    string forward(int steps) {
        while(steps>0 && !future.empty()){
            past.push(cur);
            cur=future.top();
            future.pop();
            steps--;
        }
        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
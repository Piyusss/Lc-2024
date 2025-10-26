using ll=long long;

class Bank{
public:

    vector<ll>b;
    int n;

    Bank(vector<ll>&v):b(v),n(v.size()){}

    bool transfer(int x,int y,ll m) {
        if(x>n || y>n || b[x-1]<m) return 0;

        b[x-1]-=m;
        b[y-1]+=m;

        return 1;
    }

    bool deposit(int x,ll m) {
        if(x>n) return 0;
        b[x-1]+=m;
        return 1;
    }

    bool withdraw(int x,ll m) {
        if(x>n || b[x-1]<m) return 0;
        b[x-1]-=m;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
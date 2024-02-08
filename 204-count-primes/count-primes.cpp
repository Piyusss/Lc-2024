class Solution {
public:
vector<int>f(int n) {
    vector<bool>isPrime(n + 1, true);
    vector<int>primes;
    for(int p=2;p*p<=n;p++)if(isPrime[p])for(int i=p*p;i<=n;i+=p)isPrime[i]=false;
    for(int p=2;p<=n;p++)if(isPrime[p])primes.push_back(p);
    return primes;
}
    int countPrimes(int n) {
        return f(n-1).size();
    }
};
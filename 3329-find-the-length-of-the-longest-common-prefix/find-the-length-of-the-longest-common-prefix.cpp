struct Node {
    Node* links[10];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - '0'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch - '0']; 
    }

    void put(char ch, Node* node) {
        links[ch - '0'] = node;
    }
};

class Trie {
public:
    Node* root; 

public:
    Trie() {
        root = new Node(); 
    }

    void insert(string word) {
        Node* node = root; 
        for (int i = 0; i < word.size(); i++) { 
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]);
        }
    }

};

class Solution {
public:

int f(string &s,Node* r){
    int n=s.size();
    int cnt=0;

    for(int i=0;i<n;i+=1){
        char ch=s[i];
        if(r->containsKey(ch)){
            cnt+=1;
            r=r->get(ch);
        }
        else break;
    }

    return cnt;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();

        Trie t;
        for(auto &c:arr1) t.insert(to_string(c));

        Node* r=t.root;

        int res=0;
        for(auto &c:arr2){
            string s=to_string(c);
            res=max(res,f(s,r));
        }

        return res;
    }
};
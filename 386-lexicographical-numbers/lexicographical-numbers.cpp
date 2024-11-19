struct Node {
    Node* links[10];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool flag = false;

    bool containsKey(int idx) {
        return (links[idx] != NULL); 
    }

    Node* get(int idx) {
        return links[idx]; 
    }
    
    void put(int index, Node* node) {
        links[index] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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
            if (!node->containsKey(word[i]-'0')) {
                node->put(word[i]-'0', new Node()); 
            }
            node = node->get(word[i]-'0');
        }
        node->setEnd();
    }
};

class Solution {
public:

vector<int>res;

void dfs(Node* root,int num){
    if(!root) return;

    if(root->isEnd()) res.push_back(num);

    for(int i=0;i<=9;i++){
        if(root->containsKey(i)){
            dfs(root->get(i),num*10+i);
        }
    }

}

    vector<int> lexicalOrder(int n){
        Trie trie;
        for(int i=1;i<=n;i+=1) trie.insert(to_string(i));

        Node* rooted=trie.root;
        dfs(rooted,0);

        return res;

    }
};
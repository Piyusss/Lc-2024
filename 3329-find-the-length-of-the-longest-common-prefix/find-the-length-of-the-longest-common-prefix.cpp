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

    void put(int idx, Node* node) {
        links[idx] = node;
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

int f(string num,Node* rooted){
    int cnt=0;

    for(auto &it:num){
        if(rooted->containsKey(it-'0')){
            cnt+=1;
            rooted=rooted->get(it-'0');
        }
        else break;
    }

    return cnt;

}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(auto &it:arr1) trie.insert(to_string(it));

        int maxi=0;
        Node* rooted=trie.root;
        for(auto &it:arr2) maxi=max(maxi,f(to_string(it),rooted));

        return maxi;

    }
};
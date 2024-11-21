string currentWord;

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch - 'a']; 
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    void increaseEnd() {
        cntEndWith++; 
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--; 
    }

    void reducePrefix() {
        cntPrefix--; 
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
            node->increasePrefix(); 
        }
        node->increaseEnd();
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            }else{
                return 0;
            }
        }
        return node->cntEndWith; 
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            }else{
                return 0; 
            }
        }
        return node->cntPrefix; 
    }

    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]);
                node->reducePrefix(); 
            } else {
                return; 
            }
        }
        node->deleteEnd(); 
    }
};

vector<pair<int,int>>directions={{-1,0},{0,-1},{0,1},{1,0}};

class Solution {
public:

void dfs(int x, int y, Node *node, vector<vector<char>> &grid, vector<vector<bool>> &vis, string &currentWord, unordered_set<string> &res){
    int n=grid.size();
    int m=grid[0].size();

    vis[x][y]=1;
    currentWord += grid[x][y];

    if(node->isEnd()) res.insert(currentWord);

    for(auto &it:directions){
        int newX=x+it.first;
        int newY=y+it.second;

        if(newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY]){
            char nextChar=grid[newX][newY];
            if(node->containsKey(nextChar)){
                dfs(newX,newY,node->get(nextChar),grid,vis,currentWord,res);
            }
        }
    }

    vis[x][y]=0;
    currentWord.pop_back();

}

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& dictionary) {
        Trie trie;
        for(auto &it:dictionary)trie.insert(it);

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,0));
        Node* root=trie.root;

        unordered_set<string>res;

        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                char startChar=grid[i][j];
                if(root->containsKey(startChar)){
                    currentWord = "";
                    dfs(i, j, root->get(startChar), grid, visited, currentWord, res);
                }
            }
        }

        vector<string>final;
        for(auto &it:res) final.push_back(it);

        return final;
    }
};
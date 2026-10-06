/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    bool f2(int x,int y,int n,vector<vector<int>>&grid){
        int val=grid[x][y];
        for(int i=x;i<x+n;i++) for(int j=y;j<y+n;j++) if(grid[i][j] != val) return 0;
        return 1;
    }

    Node* f(int i,int j,int n,vector<vector<int>>&grid){
        bool check=f2(i,j,n,grid);

        if(check) return new Node(grid[i][j],true);

        Node* root=new Node(777,false);
        root->topLeft=f(i,j,n>>1,grid);
        root->topRight=f(i,j+(n>>1),n>>1,grid);
        root->bottomLeft=f(i+(n>>1),j,n>>1,grid);
        root->bottomRight=f(i+(n>>1),j+(n>>1),n>>1,grid);
        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return f(0,0,n,grid);
    }
};
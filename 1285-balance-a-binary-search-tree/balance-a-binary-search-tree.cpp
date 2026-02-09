class Solution {
public:

vector<int>a;

void f1(TreeNode* u){
    if(!u) return;

    f1(u->left);
    a.push_back(u->val);
    f1(u->right);
}

TreeNode* f2(int l,int r){
    if(l>r)return nullptr;

    int m=(l+r)>>1;
    TreeNode* x=new TreeNode(a[m]);

    x->left=f2(l,m-1);
    x->right=f2(m+1,r);

    return x;
}
    TreeNode* balanceBST(TreeNode* r) {
        f1(r);
        return f2(0,(int)a.size()-1);
    }
};
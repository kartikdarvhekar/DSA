class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL ) return NULL;
        int maxx=max(p->val,q->val);
        int minn=min(p->val,q->val);
        if(minn<root->val && maxx>root->val) return root;
        else if(minn==root->val || maxx==root->val) return root;
        else if(maxx<root->val) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);

    }
};
class Solution {
public:
    void helper(TreeNode* root,int& sum){
        if(root==NULL) return;
        helper(root->right,sum);
        root->val+=sum;
        sum=root->val;
        helper(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return root;
        int sum=0;
        helper(root,sum);
        return root;
    }
};
class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pre=root->left;
        while(pre->right!=NULL){
            pre=pre->right;
        }
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1: leaf node
            if(root->right==NULL && root->left==NULL) return NULL;
            // case 2: one child node
            else if(root->right==NULL || root->left==NULL){
                if(root->left==NULL) return root->right;
                if(root->right==NULL) return root->left;
            }
            // case 3: two child nodes
            else if(root->left!=NULL && root->right!=NULL){
                TreeNode* pred=iop(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
            }
        }
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else root->left=deleteNode(root->left,key);
        return root;

    }
};
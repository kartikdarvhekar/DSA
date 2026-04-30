class Solution {
public:
    void insert(TreeNode* root,int val){   
        if(root==NULL) return;
        if(val>root->val){// insert at right
            if(root->right==NULL){
                root->right=new TreeNode(val);
                return ;
            }
            else insert(root->right,val);
        }
        else{
            if(root->left==NULL){
                root->left=new TreeNode(val);
                return;
            }
             else insert(root->left,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root==NULL) return new TreeNode(val);
         insert(root,val);
         return root;
    }
};
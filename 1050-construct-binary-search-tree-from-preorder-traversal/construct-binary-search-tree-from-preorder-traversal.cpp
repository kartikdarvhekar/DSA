class Solution {
public:
    void helper(TreeNode* root,int val){
        if(root==NULL ) return;
        if(val<root->val){
            if(root->left==NULL){
                root->left=new TreeNode(val);
                return;
            }
            else helper(root->left,val);

        }
        if(val>root->val){
            if(root->right==NULL){
                root->right=new TreeNode(val);
                return;

            }
            else helper(root->right,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
            helper(root,pre[i]);
        }
        return root;
    }
};
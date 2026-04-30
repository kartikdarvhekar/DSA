
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        vector<int>in;
        inorder(root,in);
        
        for(int i=1;i<in.size();i++){
            if(in[i-1]>=in[i]) return false;
        }
        return true;
        

    }
};
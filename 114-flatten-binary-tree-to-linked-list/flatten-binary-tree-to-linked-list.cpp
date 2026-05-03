class Solution {
public:
    void helper(vector<TreeNode*>&ans,TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root);
        helper(ans,root->left);
        helper(ans,root->right);
    }
    void flatten(TreeNode* root) {
        // Preorder
        
        vector< TreeNode* >arr;
        helper(arr,root);
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            arr[i]->right=arr[i+1];
            arr[i]->left=NULL;
        }

    }
};
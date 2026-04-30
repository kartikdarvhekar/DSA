
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
        vector<int>ans=in;
        sort(ans.begin(),ans.end());
        for(int i=0;i<in.size();i++){
            if(ans[i]!=in[i]) return false;
            if(i<in.size()-1){
                if(ans[i]==ans[i+1]) return false;
            }
        }
        return true;
        

    }
};
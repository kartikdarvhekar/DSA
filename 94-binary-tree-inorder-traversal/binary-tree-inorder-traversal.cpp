class Solution {
public:
    // MORRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            // finding predecessor
            if(curr->left!=NULL){
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                //linking
                if(pred->right==NULL) {
                    pred->right=curr;
                    curr=curr->left;
                }
                else {
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                 ans.push_back(curr->val);
                 curr=curr->right;


            }
            

        }
        return ans;
    }
};
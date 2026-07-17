class Solution {
public:
    TreeNode* first=NULL;
    void makeParentMap(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL) parent[root->left]=root;
        if(root->right) parent[root->right]=root;
        makeParentMap(parent,root->left);
        makeParentMap(parent,root->right);

    }
    void find(TreeNode* root,int start){
        if(root==NULL) return;
        if(root->val==start){
            first=root;
        }
        find(root->right,start);
        find(root->left,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        makeParentMap(parent,root);
        find(root,start);
        unordered_set<TreeNode*>s;
        s.insert(first);
        queue< pair<TreeNode*,int> >q;// TreeNode and level
        q.push({first,0});
        int maxlevel=0;
        while(q.size()>0){
            pair<TreeNode*,int>p=q.front();
            q.pop();
            int level=p.second;
            maxlevel=max(maxlevel,level);
            TreeNode* temp=p.first;
            if(temp->left){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }
            if(parent.find(temp)!=parent.end()){
                if(s.find(parent[temp])==s.end()){
                    q.push({parent[temp],level+1});
                    s.insert(parent[temp]);
                }
            }


        }
        return maxlevel;
    }
};
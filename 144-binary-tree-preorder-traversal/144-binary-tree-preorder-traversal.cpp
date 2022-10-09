class Solution {
vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal( root->right);
        return ans;
    }
};
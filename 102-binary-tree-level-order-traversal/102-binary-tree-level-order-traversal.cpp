class Solution {
public:
    void solution(TreeNode* node, vector<vector<int>> &ans, int level){
        if(node == nullptr) return; 
        
        if(ans.size() <= level){
            ans.push_back({});
        }
        
        ans[level].push_back(node->val);
        solution(node->left, ans, level + 1);
        solution(node->right, ans, level + 1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;  
        solution(root, ans, 0);
        return ans;
    }
};
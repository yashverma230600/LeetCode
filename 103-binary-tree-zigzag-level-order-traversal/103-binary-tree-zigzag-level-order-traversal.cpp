/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int flag = true;
        vector<int> v;
        while (!q.empty())
        {

            TreeNode *n = q.front();
            q.pop();
            if (n)
            {
                v.push_back(n->val);
                if (n->left)
                {
                    q.push(n->left);
                }
                if (n->right)
                {
                    q.push(n->right);
                }
            }
            else if (!q.empty())
            {
                if (flag)
                {
                    ans.push_back(v);
                }
                else
                {
                    // cout << "flag: " << flag << endl;
                    reverse(v.begin(), v.end());
                    ans.push_back(v);
                }
                q.push(NULL);
                v.clear();
                flag = !flag;
            }
        }

        if (flag)
        {
            ans.push_back(v);
        }
        else
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};
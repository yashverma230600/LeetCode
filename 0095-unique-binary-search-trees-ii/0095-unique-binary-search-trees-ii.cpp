#define vi vector<int>
#define vvi vector<vi>
#define trav(v) for(auto x:v)
#define trav2(v2) for(auto y:v2)
class Solution {
public:
    vector<TreeNode *> fn(vector<int> v)
{
    int n = v.size();
    if (n == 1)
        return {new TreeNode(v[0])};
    if (n == 0)
        return {NULL};
    vvi left(n);
    vvi right(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (v[j] < v[i])
                    left[i].push_back(v[j]);
                else
                    right[i].push_back(v[j]);
            }
        }
    }
    vector<vector<TreeNode *>> leftNodes(n);
    vector<vector<TreeNode *>> rightNodes(n);
    for (int i = 0; i < n; i++)
    {
        leftNodes[i] = fn(left[i]);
        rightNodes[i] = fn(right[i]);
    }
    vector<TreeNode *> ans;
    for (int i = 0; i < n; i++)
    {
        trav(leftNodes[i])
        {
            TreeNode *a = new TreeNode(v[i]);
            a->left = x;
            trav2(rightNodes[i])
            {
                TreeNode *a2 = new TreeNode(v[i]);
                a2->left = a->left;
                a2->right = y;
                ans.push_back(a2);
            }
        }
    }
    return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        vi v;
        for(int i= 1;i<=n;i++) v.push_back(i);
    vector<TreeNode *> ans = fn(v);
        return ans;
    }
};
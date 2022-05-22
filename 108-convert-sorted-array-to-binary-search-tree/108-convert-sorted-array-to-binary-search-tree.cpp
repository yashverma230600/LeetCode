class Solution {
public:
    TreeNode* fun(vector<int>& nums,int low,int high)
    {
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=fun(nums,low,mid-1);
        root->right=fun(nums,mid+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return fun(nums,low,high);
    }
};
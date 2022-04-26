class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    
     TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start>end)
            return NULL;
         int mid = start + (end - start)/2;
         TreeNode* BSTtree = new TreeNode(nums[mid]);
         BSTtree->left=helper(nums,start,mid-1);
         BSTtree->right = helper(nums,mid+1,end);
          return BSTtree;
    }
   
};
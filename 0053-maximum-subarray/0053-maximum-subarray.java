class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum=0;
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            maxSum+=nums[i];
            ans=Math.max(ans,maxSum);
            if(maxSum<0){
                maxSum=0;
            }
            
        }

        return ans;
    }
}
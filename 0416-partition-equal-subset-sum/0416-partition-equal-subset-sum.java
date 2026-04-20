class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum=0;
        for(int num:nums) totalSum+=num;

        if(totalSum%2!=0) return false;
        int tSum=totalSum/2;

        boolean[] dp = new boolean[tSum+1];
        dp[0] = true;

        for(int num:nums){
            for(int currSum=tSum;currSum>=num;currSum--){
                dp[currSum] = dp[currSum] || dp[currSum-num];
                if(dp[tSum]) return true;
            }
        }
        return dp[tSum];
    }
}
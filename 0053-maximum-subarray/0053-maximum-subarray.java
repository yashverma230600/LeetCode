class Solution {
    public int maxSubArray(int[] nums) {
     int ans=Integer.MIN_VALUE;
     int mSum=0;
     for(int i=0;i<nums.length;i++){
        if(mSum<0){
            mSum=0;
            
        }
        
            mSum+=nums[i];
            ans=Math.max(mSum,ans);
        
     }
     return ans;
    }
}
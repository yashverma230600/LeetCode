class Solution {
    public int maxSubArray(int[] nums) {
        int ans=0,Msum=nums[0];
        for(int i=0;i<nums.length;i++){
            if(Msum<0){
                Msum=0;
            }
            Msum+=nums[i];
            ans=Math.max(ans,Msum);
            
        }
        return ans;
    }
}
class Solution {
    public int longestOnes(int[] nums, int k) {
        int r=0,l=0,maxLen=0,zeros=0;
        while(r<nums.length){
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxLen=Math.max(maxLen,len);
            }
            r++;

        }
        return maxLen;
    }
}
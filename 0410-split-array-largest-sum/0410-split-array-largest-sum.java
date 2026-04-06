class Solution {

    public boolean isPossible(int[] nums,int mid,int k){
        int count=1,sum=0;
        for(int i=0;i<nums.length;i++){
            if(sum+nums[i]<=mid) sum+=nums[i];
            else{
                count++;
                sum=nums[i];
            }


        }
        return count<=k;

    }
    public int splitArray(int[] nums, int k) {
        int res=-1;int low=0;int high=0;
        for(int i=0;i<nums.length;i++){
            low=Math.max(low,nums[i]);
            high+=nums[i];
        }
        
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums,mid,k)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
}
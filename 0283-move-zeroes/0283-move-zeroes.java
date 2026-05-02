class Solution {
    public void moveZeroes(int[] nums) {
        int l=0,r=0;
        for(int i=0;i<nums.length;i++){
            if(nums[r]!=0){
                int temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                l++;r++;
            }else{
                r++;
            }
        }
    }
}
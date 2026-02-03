class Solution {

    public void swap(int[] nums, int start, int end){
        // int temp = nums[end];
        // nums[end] = nums[start];
        // nums[start] = temp;
        int temp=nums[end]; 
                nums[end] = nums[start];
                nums[start] = temp;
    }


    public void sortColors(int[] nums) {
            int start = 0,mid = 0, high = nums.length-1;
            while(mid<=high){
                switch(nums[mid]){

                case 0:swap(nums,start,mid);
                start++;
                mid++;
                break;
                case 1:
                mid++;
                break;
                case 2:
                
                swap(nums,mid,high);
                high--;
                break;
                }
            }
    }
}
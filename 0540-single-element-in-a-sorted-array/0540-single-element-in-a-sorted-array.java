class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int n = nums.length;
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int left=1,right=n-2;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
                return nums[mid];

            //we are in left
            if((mid%2==1 && nums[mid]==nums[mid-1] ) || (mid%2==0 && nums[mid+1]==nums[mid] )){
                left=mid+1;
            }
            //we are in right
            else{
                right=mid-1;
            }
        }
        return -1;

    }
}
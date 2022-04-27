class Solution {
public:
        
        
        
        int searchInsert(vector<int>& nums, int target) {
    
    int n=nums.size();
    
    int l=0,h=n-1,res=0;
    
    while(l<=h){
        
        int mid=l+(h-l)/2;
        
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            h=mid-1;
        }
        else{
            // res=mid+1;  //res=mid is the floor value, add 1 to it
            l=mid+1;
        }
    }
    return l;
}
    
};
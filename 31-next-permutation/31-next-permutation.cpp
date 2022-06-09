class Solution {
public:
        //method 1. -->> next_permutation(nums.begin(),nums.end());    //c++ built-in stl
        //method 2.-------------
        //by finding element that is lower than its left elements --> index
        //if doesnt (find any then it is the peak permutation of and just reverse array)
        //if finded, now find greater element than its value --> i , and swap it 
        //finally reverse elements from index+1 to end
        //TC:O(N)   //SC:O(1)
    void nextPermutation(vector<int>& nums) {
        int index,i;
        int n = nums.size();
        if(nums.size()<=1) return;
        for(index = n-2;index>=0;index--){
            if(nums[index]<nums[index+1]) 
                break;       
        }
        
        //If it is peak purmutation
        if(index < 0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(i = n-1;i>index;i--){
                if(nums[i]>nums[index])                    
                    break;               
            }
            swap(nums[i],nums[index]);
            reverse(nums.begin()+index+1,nums.end());
        }
    }
};
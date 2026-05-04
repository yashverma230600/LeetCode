class Solution {
    public int trap(int[] height) {
        int l=0,r=height.length-1,Rmax=0,Lmax=0,total=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(Lmax>height[l]){
                    total+=Lmax-height[l];
                }
                else{
                    Lmax=height[l];
                }
                l++;
            }
            else{
                 if(Rmax>height[r]){
                    total+=Rmax-height[r];
                }
                else{
                    Rmax=height[r];
                }
                r--;
            

            }
        }
        return total;
    }
}
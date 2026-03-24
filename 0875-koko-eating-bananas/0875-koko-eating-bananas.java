class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max=piles[0];
        int sum=0;
        for(int i=0;i<piles.length;i++){
          if(max<piles[i]){
            max=piles[i];
          }
          sum+=piles[i];
        }
        int low=1;
        int high=max;
        int min=Integer.MAX_VALUE;
        while(low<=high){
          int mid=low+(high-low)/2;

          
          if(solve(mid,h,piles)){
            min=mid;
            high=mid-1;
          }
          else {
            low=mid+1;
          }
        }
        return min;
    }

    public static boolean solve(int mid, int h, int piles[]){
    long hours = 0;

    for(int i = 0; i < piles.length; i++){
        hours += (piles[i] + mid - 1) / mid; 
    }

    return hours <= h;
}
}
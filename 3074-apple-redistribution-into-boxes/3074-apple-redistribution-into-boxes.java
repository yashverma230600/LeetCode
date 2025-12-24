class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int sum=0;
        int c=0;
     for(int i:apple)   {
        sum+=i;
     }
     Arrays.sort(capacity);
     for(int j=capacity.length-1;j>=0;j--){
        sum-=capacity[j];
        c++;
        if(sum<=0) return c;
     }
     return c;
    }
}
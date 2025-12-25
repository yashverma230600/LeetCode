class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int n=happiness.length;
        long ans=0;
        int test=0;
        for(int i=n-1;i>=0;i--){
            ans=ans+Math.max((happiness[i]-test),0);
            test++;
            if(test==k){
                break;
            }
        }
        return ans;
    }
}
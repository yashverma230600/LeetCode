class Solution {
    public int numOfSubarrays(int[] arr) {
        final int MOD = 1000000007;
        int PrefixSum=0,oddCount=0,evenCount=1,res=0;
        for(int i:arr){
            PrefixSum+=i;
            if(PrefixSum%2==0){
                res=(res+oddCount)%MOD;
                evenCount++;
            }
            else{
                res=(res+evenCount)%MOD;
                oddCount++;
            }
        }
        return res;
    }
}
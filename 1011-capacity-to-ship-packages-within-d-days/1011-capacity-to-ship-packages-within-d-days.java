class Solution {

    public int isAns(int[] arr, int capacity){
        int day=1;
        int load=0;
        for(int num:arr){
            if(load+num>capacity){
                day++;
                load=num;
            }
            else{
                load+=num;
            }

        }
                    return day;

    }
    
    public int shipWithinDays(int[] weights, int days) {
        

        int l=0,r=0,sum=0;
        for(int i=0;i<weights.length;i++){
            l=Math.max(l,weights[i]);
            sum+=weights[i];
        }
        r=sum;
                    int ans=0;


        while(l<=r){
            int mid=(l+r)/2;
            int noOfDays=isAns(weights,mid);
            if(noOfDays<=days) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
}
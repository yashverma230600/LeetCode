package Binary_search;

public class Sqrt {
    

    public int mySqrt(int n){
        if(n==0 || n==1) return n;

        int l=1,r=n;

        while(l<=r){
            int mid = (l+r)/2;

            if((long)mid*mid    == n) return mid;
            else if((long)mid*mid>n) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
    public static void main(String[] args) {
        Sqrt sol = new Sqrt();
        int n = 36;
        int result = sol.mySqrt(n);
        System.out.println("Output: " + result); // Expected: 6
    }
    
}

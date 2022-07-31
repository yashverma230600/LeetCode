class Solution {
public:
    int fib(int n) {
        
       int f0=0,f1=1,f;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        for(int i=2;i<=n;i++){
            f=f0+f1;
            f0=f1;
            f1=f;
        }
        return f;
        
    }
};
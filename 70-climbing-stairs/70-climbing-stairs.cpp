class Solution {
public:
    int climbStairs(int n) {
        
         //Edge cases
    if(n == 0) return 1;
    if(n == 1) return 1;

    int *ans = new int [n+1];  //Create an array to store the values of overlapping subproblems
    ans[0] = ans[1] = 1;       //Fill the independent values in the array
 
    for(int i=2; i<=n; i++)    //Now fill the dependent vales in the array
        ans[i] = ans[i-1] + ans[i-2];
    return ans[n];
        
    }
};
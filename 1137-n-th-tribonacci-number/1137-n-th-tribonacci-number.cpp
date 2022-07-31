class Solution {
public:
    int tribonacci(int n) {
        vector<int> data(n+1);
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        data[0] = 0;
        data[1] = 1;
        data[2] = 1;
        for(int i = 3; i <= n; i++){
            data[i] = data[i-1] + data[i-2] + data[i-3];
        }
        
        return data[n];
    }
};
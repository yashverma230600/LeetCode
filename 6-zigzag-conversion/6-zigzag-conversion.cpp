class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        string f=""; 
        int first=(2*n-4),second=2; //when the interation is between > 0 and < n-1 we need to increment second by 2 and dec first by2 
            for(int i=0;i<n;i++){
                if(i==0 || i==n-1){
                    for(int j=i;j<s.length();j+=(2*n-2)){ 
                        f+=s[j];
                    }
                }
                else{
                    int j=i,cnt=0;
                    while(j<s.length()){
                        f+=s[j]; 
						//depending upon the cnt we will now update j as for each iteration the value to be added in j is different
                        if(cnt%2==0){ 
                            j+=first;
                        }
                        else{
                            j+=second;
                        }
                        cnt+=1;
                    }
                    first-=2;
                    second+=2;
                }
            }
        return f;
    }
};
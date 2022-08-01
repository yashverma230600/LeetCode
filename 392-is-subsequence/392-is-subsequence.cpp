class Solution {
public:
    bool isSubsequence(string s, string t) {
        
      
        int j=0;
        int n=s.length(),m=t.length();
        if(n==0){
            return true;
        }
        for(int i=0;i<m;i++){
            
                if(s[j]==t[i]){
                    j++;
                   
                    
                
            }
        if(j>=n)
            return true;
        
    }
        return false;
    }
};
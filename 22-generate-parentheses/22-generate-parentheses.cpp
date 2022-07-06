class Solution {
public:
    void solve(int n, int openings , int closings , string temp, vector<string> &ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return ;
        }
        
        if(openings<n){
           
            solve(n,openings+1,closings,temp+'(',ans);
        }
        
        if(closings<openings){
            
            solve(n,openings,closings+1,temp+')',ans);
        }
          return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};
class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& v, vector<int>& c, int t, int idx) {
        if(t == 0) { ans.push_back(v); return; }
        
        for(int i = idx; i<c.size(); i++){
            if(t - c[i] < 0) break;
            
            // in this way, we can skip same number from current level
            // so vector v will be something like this v{1, ...}, v{2, ...}, v{5, ...}
            if(idx < i && c[i-1] == c[i]) { continue; }
            
            v.push_back(c[i]);
            f(ans, v, c, t - c[i], i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans; vector<int> v;
        
        sort(c.begin(), c.end());
        
        f(ans, v, c, t, 0);
        
        return ans;
    }
};
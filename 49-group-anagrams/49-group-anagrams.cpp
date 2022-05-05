class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> umap;
        for (string s: strs)
            umap[hasher(s)].push_back(s);

        vector<vector<string>> ans;
        for (auto i: umap)
            ans.push_back(i.second);
        
        return ans;
    }
    
     string hasher(string s) {
         sort(s.begin(), s.end());
         return s;
     }
};
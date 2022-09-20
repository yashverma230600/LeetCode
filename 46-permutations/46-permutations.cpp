class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> visited;
    vector<int> tmp;
    size_t n = 0;
    void dfs(int i, vector<int>& nums)
    {
        if(i == n){
            ans.push_back(tmp);
            return;
        }
        for(int j = 0; j < n; ++j)
        {
            if(visited[j]){
                continue;
            }
            visited[j] = true;
            tmp.push_back(nums[j]);
            dfs(i+1, nums);
            visited[j]= false;
            tmp.pop_back();
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visited.resize(n,false);
        dfs(0, nums);
        return ans;
    }
};
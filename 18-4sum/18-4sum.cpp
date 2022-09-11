class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>s;
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
            long long t=target-nums[i];
            
            for(int j=i+1;j<n;j++){
                int f=j+1;
                int l=n-1;
                while(f<l){
                    if((long long) nums[j]+nums[f]+nums[l]==t){ 
                        s.insert({nums[i],nums[j],nums[f++],nums[l--]});
                    }
                    
                    else if((long long) nums[j]+nums[f]+nums[l]>t) l--; 
                    else f++;
                }
                
            }
        }
        
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};
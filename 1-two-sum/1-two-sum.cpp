class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        for(int ele : nums){
           if(target - ele == ele && mp[ele].size() > 1){
               return {mp[ele][0], mp[ele][1]};
           }
           if(mp.find(target - ele) != mp.end() && mp[target - ele] != mp[ele]){
               return {mp[ele][0], mp[target - ele][0]};
           }
        }
        return {};
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        multiset<int> m;
        m.insert(nums.begin(),nums.end());
        m.erase(val);
        nums.clear();
        nums.assign(m.begin(),m.end());
        return nums.size();
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int &n1:nums){
            s.insert(n1);
        }
        int ind = 0;
        for(auto it=s.begin(); it!=s.end(); it++){
            nums[ind] = (*it);
            ind++;
        }
        return s.size();
    }
};
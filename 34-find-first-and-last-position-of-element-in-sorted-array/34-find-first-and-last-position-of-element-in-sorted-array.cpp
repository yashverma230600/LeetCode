class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    int l = 0;
    int r = nums.size() - 1;
    int mid;
    vector<int> solution = {-1,-1};
        
    // Two binary searches. Continue search, if found. One direction will lead to
    // lowerbound(). The other direction will lead to upperbound() - 1
        
    while (l <= r)
    {
        mid = (r + l) / 2;
        
        if (nums[mid] == target)
        {
            solution[0] = mid;
            r = mid - 1;
        }
        else if (nums[mid] > target)
            r = mid - 1;
        else if (nums[mid] < target)
            l = mid + 1;
    }
        
    l = 0;
    r = nums.size() - 1;
        
     while (l <= r)
    {
        mid = (r + l) / 2;
        
        if (nums[mid] == target)
        {
            solution[1] = mid;
            l = mid + 1;
        }
        else if (nums[mid] > target)
            r = mid - 1;
        else if (nums[mid] < target)
            l = mid + 1;
    }
        
    return solution;
        
    }
};
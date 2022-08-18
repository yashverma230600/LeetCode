class Solution {
public:
    static int thirdMax(vector<int>& nums) {
	    //  at most 3n comparisons O(n)
        make_heap(nums.begin(), nums.end());
        const int max = nums.front();
		if(nums.size() < 3) { return max; }
		int distinct = 1;
        int thirdMax = max;
        
		// Average case: O(log n): 
        //    when there only distinct elements, or only a few duplicate 1st and 2nd max values,
        //    pop_heap is called on average a constant number of times.
		// Worst case: O(n log n):
        //    heap sort is fully performed on the range, and the 3rd max does not exist in the array.
        while(distinct != 3) {
		    //  at most 2 * logn comparisons
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
			//  third max not found, return true max
            if(nums.empty()) { return max; }
			//  if current max is distinct
            if(thirdMax != nums.front()) {
                thirdMax = nums.front();
                ++distinct;
            }
        }

        return thirdMax;
    }
};
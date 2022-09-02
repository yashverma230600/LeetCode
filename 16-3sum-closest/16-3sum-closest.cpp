class Solution {

public:
	int threeSumClosest(vector<int>& nums, int target) {
	
		sort(nums.begin(), nums.end());
		int lower;
		int upper;
		int leftBoundary = 0;
		int rightBoundary = 0;
		int left = 0;
		int right = nums.size() - 1;
		int currentClosest = 10000000;
		int closest = currentClosest;
		do{

			int upper = lower_bound(nums.begin() + left + 1, nums.begin() + (right - 1), target - nums[left] - nums[right]) - nums.begin();
			if(nums[upper] <=  target - nums[left] - nums[right]){
				lower = upper;
			}
			else{
				lower = max(upper-1, left+1);
			}


			if(abs(target - nums[left] - nums[right] - nums[lower]) > abs(target - nums[left] - nums[right] - nums[upper])){
				currentClosest = nums[left] + nums[right] + nums[upper];
			}
			else{
				currentClosest = nums[left] + nums[right] + nums[lower];
			}

			if(abs(currentClosest - target) < abs(closest - target)){
				closest = currentClosest;
			}

			if(lower == left + 1){
				rightBoundary++;
				right = nums.size() - rightBoundary - 1;
				left = leftBoundary;
				continue;
			}

			if(upper == right - 1){
				left++;
				leftBoundary++;
				right = nums.size() - rightBoundary - 1; 
				continue;
			}

			right--;

		}
		while(right - left > 1 && closest != target);

		return closest;
	}
};
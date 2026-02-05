class Solution {

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int index = -1;

        // 1️⃣ Find first decreasing element from right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // 2️⃣ If no such index, reverse whole array
        if (index == -1) {
            reverse(nums, 0, n - 1);
            return;
        }

        // 3️⃣ Find element just greater than nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums, i, index);
                break;
            }
        }

        // 4️⃣ Reverse the suffix
        reverse(nums, index + 1, n - 1);
    }

    // helper methods
    void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void reverse(int[] nums, int l, int r) {
        while (l < r) {
            swap(nums, l, r);
            l++;
            r--;
        }
    }
}

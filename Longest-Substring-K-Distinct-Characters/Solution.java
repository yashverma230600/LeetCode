import java.util.HashMap;

/**
 * Longest Substring with At Most K Distinct Characters
 * 
 * Problem: Find the length of the longest substring that contains at most k distinct characters.
 * 
 * Approach: Sliding Window with HashMap
 * - Use two pointers (left and right) to maintain a window
 * - Expand window by moving right pointer and adding characters
 * - When window has more than k distinct characters, shrink from left
 * - Track maximum window size
 * 
 * Time Complexity: O(n) - each character visited at most twice
 * Space Complexity: O(k) - HashMap stores at most k distinct characters
 */
public class Solution {

    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int l = 0, maxL = 0;
        HashMap<Character, Integer> map = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) + 1);

            // Shrink window if more than k distinct characters
            while(map.size() > k){
                map.put(s.charAt(l), map.get(s.charAt(l)) - 1);
                if(map.get(s.charAt(l)) == 0){
                    map.remove(s.charAt(l));
                }
                l++;
            }
            
            // Update maximum length
            maxL = Math.max(maxL, i - l + 1);
        }
        return maxL;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Test case 1
        String s1 = "aaabbccd";
        int k1 = 2;
        int result1 = sol.lengthOfLongestSubstringKDistinct(s1, k1);
        System.out.println("Input: \"" + s1 + "\", k = " + k1);
        System.out.println("Output: " + result1);
        System.out.println("Expected: 4 (substring: \"aabb\" or \"bbcc\")\n");
        
        // Test case 2
        String s2 = "abcabcabcabc";
        int k2 = 2;
        int result2 = sol.lengthOfLongestSubstringKDistinct(s2, k2);
        System.out.println("Input: \"" + s2 + "\", k = " + k2);
        System.out.println("Output: " + result2);
        System.out.println("Expected: 4 (substring: \"abca\")\n");
        
        // Test case 3
        String s3 = "aabbccc";
        int k3 = 2;
        int result3 = sol.lengthOfLongestSubstringKDistinct(s3, k3);
        System.out.println("Input: \"" + s3 + "\", k = " + k3);
        System.out.println("Output: " + result3);
        System.out.println("Expected: 5 (substring: \"aabbc\" or \"abbcc\")");
    }
}

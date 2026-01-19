# Longest Substring with At Most K Distinct Characters

## Problem Description

Given a string `s` and an integer `k`, find the length of the longest substring that contains **at most `k` distinct characters**.

### Examples

**Example 1:**
```
Input: s = "aaabbccd", k = 2
Output: 4
Explanation: The longest substring is "aabb" or "bbcc" with 2 distinct characters
```

**Example 2:**
```
Input: s = "abcabcabcabc", k = 2
Output: 4
Explanation: The longest substring is "abca" with 2 distinct characters
```

**Example 3:**
```
Input: s = "aabbccc", k = 2
Output: 5
Explanation: The longest substring is "aabbc" or "abbcc" with 2 distinct characters
```

---

## Approach

### Sliding Window Technique

We use a **two-pointer sliding window** approach with a **HashMap** to track character frequencies:

1. **Expand the window:** Move right pointer and add the current character to the map
2. **Shrink when needed:** When the map has more than `k` distinct characters, shrink from the left until we have at most `k` characters
3. **Track maximum:** Keep track of the maximum window size seen so far

### Algorithm Steps

```
1. Initialize: l = 0, maxL = 0, map = empty HashMap
2. For each character at position i:
   a. Add character to map (increment count)
   b. While map has more than k distinct characters:
      - Decrement count of character at l
      - Remove character if count becomes 0
      - Move l pointer forward
   c. Update maxL with current window size (i - l + 1)
3. Return maxL
```

---

## Complexity Analysis

### Time Complexity: **O(n)**
- Each character is visited at most twice (once by right pointer `i`, once by left pointer `l`)
- HashMap operations (put, get, remove) are O(1) on average

### Space Complexity: **O(k)**
- HashMap stores at most `k` distinct characters
- In the worst case, it stores all unique characters in the substring

---

## Code

```java
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
```

---

## Step-by-Step Example

**Input:** `s = "aaabbccd"`, `k = 2`

| i | char | l | window | map | size | maxL |
|---|------|---|--------|-----|------|------|
| 0 | 'a' | 0 | "a" | {a:1} | 1 | 1 |
| 1 | 'a' | 0 | "aa" | {a:2} | 1 | 2 |
| 2 | 'a' | 0 | "aaa" | {a:3} | 1 | 3 |
| 3 | 'b' | 0 | "aaab" | {a:3, b:1} | 2 | 4 |
| 4 | 'b' | 0 | "aaabb" | {a:3, b:2} | 2 | 5 |
| 5 | 'c' | 2 | "abbc" | {a:1, b:2, c:1} | 3 | Shrink! |
| 5 | 'c' | 3 | "bbc" | {b:2, c:1} | 2 | 3 |
| 6 | 'c' | 3 | "bbcc" | {b:2, c:2} | 2 | 4 |
| 7 | 'd' | 5 | "ccd" | {c:2, d:1} | 2 | 3 |

**Result:** `maxL = 4`

---

## How to Compile and Run

```bash
# Navigate to directory
cd "Longest-Substring-K-Distinct-Characters"

# Compile
javac Solution.java

# Run
java Solution
```

**Expected Output:**
```
Input: "aaabbccd", k = 2
Output: 4
Expected: 4 (substring: "aabb" or "bbcc")

Input: "abcabcabcabc", k = 2
Output: 4
Expected: 4 (substring: "abca")

Input: "aabbccc", k = 2
Output: 5
Expected: 5 (substring: "aabbc" or "abbcc")
```

---

## Key Points

✅ **Efficient:** O(n) time complexity - optimal solution
✅ **In-place:** Uses sliding window technique  
✅ **HashMap:** Tracks character frequencies effectively
✅ **Two Pointers:** Left and right pointers maintain valid window
✅ **Greedy Approach:** Always try to expand window, only shrink when necessary

---

## Related Problems

- Longest Substring Without Repeating Characters
- Longest Substring with At Most Two Distinct Characters
- Minimum Window Substring
- Sliding Window Maximum

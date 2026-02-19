# Find Repeating Numbers in Array

## Problem Statement
Find all repeating/duplicate numbers in an array where values are in the range [1, n].

## Solution Approach
This solution uses an **in-place marking technique** by utilizing the sign of array elements as markers to track visited numbers.

## Algorithm Explanation

### Core Strategy
- Use array indices as markers by making values negative
- If we encounter a value whose corresponding index is already negative, it's a duplicate
- Time Complexity: O(n)
- Space Complexity: O(1) (excluding result list)

## Line-by-Line Code Explanation

### Initialization
```java
List<Integer> list = new ArrayList<>();
int idx = 0;
```
- Creates an empty list to store duplicate numbers
- Declares `idx` variable to hold the calculated index

### Main Algorithm Loop
```java
for(int i=0; i<arr.length; i++){
    idx = Math.abs(arr[i])-1;
    if(arr[idx]<0){
        list.add(Math.abs(arr[i]));
    } else {
        arr[idx] = -arr[idx];
    }
}
```

**Line 1**: Loop through each element in the array

**Line 2**: Calculate index position
- `Math.abs(arr[i])` - Get absolute value (needed because we modify values to negative)
- Subtract 1 because array is 0-indexed but values are 1-indexed

**Line 3**: Check if position is already marked (negative)
- If negative, this number has been seen before → it's a duplicate

**Line 4**: Add the duplicate to result list
- Use `Math.abs()` to get the original value

**Line 6**: Mark this number as visited
- Make the value at calculated index negative

## Step-by-Step Example

**Input**: `arr = [1, 3, 2, 3, 1]`

### Iteration 1 (i=0):
- Element: `arr[0] = 1`
- Index: `idx = |1| - 1 = 0`
- Check: `arr[0] = 1` (positive, not visited)
- Action: Mark as visited → `arr[0] = -1`
- **Array**: `[-1, 3, 2, 3, 1]`
- **Result**: `[]`

### Iteration 2 (i=1):
- Element: `arr[1] = 3`
- Index: `idx = |3| - 1 = 2`
- Check: `arr[2] = 2` (positive, not visited)
- Action: Mark as visited → `arr[2] = -2`
- **Array**: `[-1, 3, -2, 3, 1]`
- **Result**: `[]`

### Iteration 3 (i=2):
- Element: `arr[2] = -2`
- Index: `idx = |-2| - 1 = 1`
- Check: `arr[1] = 3` (positive, not visited)
- Action: Mark as visited → `arr[1] = -3`
- **Array**: `[-1, -3, -2, 3, 1]`
- **Result**: `[]`

### Iteration 4 (i=3):
- Element: `arr[3] = 3`
- Index: `idx = |3| - 1 = 2`
- Check: `arr[2] = -2` (negative, **already visited!**)
- Action: Add duplicate → `list.add(3)`
- **Array**: `[-1, -3, -2, 3, 1]`
- **Result**: `[3]`

### Iteration 5 (i=4):
- Element: `arr[4] = 1`
- Index: `idx = |1| - 1 = 0`
- Check: `arr[0] = -1` (negative, **already visited!**)
- Action: Add duplicate → `list.add(1)`
- **Array**: `[-1, -3, -2, 3, 1]`
- **Result**: `[3, 1]`

## Final Output
```
Repeating numbers: [3, 1]
```

## Key Insights

1. **Index Mapping**: Value `k` uses index `k-1` as its marker
2. **Sign as Marker**: Negative sign indicates "visited"
3. **Math.abs() Usage**: Required because we modify values to negative during traversal
4. **In-Place Modification**: Array is modified but can be restored if needed
5. **Single Pass**: Only one iteration through the array needed

## Constraints

- Array values must be in range **[1, n]** where n is the array length
- This constraint allows us to use array indices as markers
- If values can be outside this range, a different approach (HashMap) would be needed

## Complexity Analysis

| Metric | Value | Explanation |
|--------|-------|-------------|
| Time Complexity | O(n) | Single pass through array |
| Space Complexity | O(1) | In-place marking (excluding result) |
| Auxiliary Space | O(k) | Where k is number of duplicates |

## Alternative Approaches

1. **HashMap**: O(n) time, O(n) space - stores frequency count
2. **Sorting**: O(n log n) time, O(1) space - sort and find consecutive duplicates
3. **Set**: O(n) time, O(n) space - track seen elements

This solution is optimal for the given constraints!

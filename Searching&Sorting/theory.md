1. Linear Search

Check every element one by one from start to end until you find the target, or reach the end.

- Works on sorted or unsorted arrays.
- Simple but slow for large arrays.

**Time Complexity:** O(n) — worst case, you check every element.
**Space Complexity:** O(1)

2. Binary Search

### Theory (Easy Words)
Only works on sorted arrays. Repeatedly cut the search space **in half**.

Steps:
1. Look at the middle element.
2. If it's the target → done.
3. If target is smaller → search only the **left half**.
4. If target is bigger → search only the **right half**.
5. Repeat until found or search space becomes empty.

**Time Complexity:** O(log n)
**Space Complexity:** O(1) iterative, O(log n) recursive (call stack)
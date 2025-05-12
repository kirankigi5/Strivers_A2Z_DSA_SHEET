# Sliding Window Technique

The Sliding Window technique is a computational method that aims to reduce the use of nested loops and replace them with a single loop, thereby reducing the time complexity.

## Overview

- A sliding window is a contiguous sequence of elements of a specific size that moves from the beginning of the array to the end.
- The technique is particularly useful for solving array/string problems that require finding subarrays that satisfy certain conditions.
- It maintains a subset of items as your window and slides over the data to process it efficiently.

## Common Use Cases

1. Finding subarrays with a given sum
2. Finding longest/shortest substring with certain conditions
3. Maximum/minimum sum subarray of size k
4. String pattern matching

## Time Complexity
- Generally reduces time complexity from O(n²) to O(n)
- Space Complexity is typically O(1)

## Types
1. Fixed Size Window
    - Window size remains constant throughout
2. Variable Size Window
    - Window size changes based on conditions

## Example Problems
- Maximum Sum Subarray of Size K
- Longest Substring Without Repeating Characters
- Minimum Window Substring

| Problem | Status | Solution |
|---------|--------|----------|
| [1. Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/) |  Solved ✅| [Solution](https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/6737698/neetcode-1838-frequency-of-the-most-freq-srec/) |
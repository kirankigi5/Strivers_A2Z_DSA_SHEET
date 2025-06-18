# 🎯 Sliding Window Technique

The Sliding Window technique is a computational method that aims to reduce the use of nested loops and replace them with a single loop, thereby reducing the time complexity.

## 📝 Overview

- A sliding window is a contiguous sequence of elements of a specific size that moves from the beginning of the array to the end.
- The technique is particularly useful for solving array/string problems that require finding subarrays that satisfy certain conditions.
- It maintains a subset of items as your window and slides over the data to process it efficiently.

## 🎯 Common Use Cases

| Category | Examples |
|----------|----------|
| 1️⃣ Array Sums | Finding subarrays with given sum |
| 2️⃣ Strings | Finding longest/shortest substring |
| 3️⃣ Fixed Size | Maximum/minimum sum subarray of size k |
| 4️⃣ Patterns | String pattern matching |

## ⚡ Complexity Analysis

| Aspect | Complexity | Improvement |
|--------|------------|-------------|
| Time | $O(n)$ | Reduced from $O(n²)$ |
| Space | $O(1)$ | Constant extra space |


| Type | Description | 
|------|-------------|
| 1️⃣ Fixed Size | Window size remains 
| 2️⃣ Variable Size | Window size changes based on conditions | 



## 📝 Problem Set

| No. | Problem | Status | Solution |
|-----|---------|--------|----------|
| 1 | [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/6737698/neetcode-1838-frequency-of-the-most-freq-srec/) |
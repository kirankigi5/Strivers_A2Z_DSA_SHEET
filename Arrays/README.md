# 🔍 Array Problems 

## 1. Find Largest Element

## 📝 Problem Statement
Given an array `arr[]` of size `N`, find the largest element in the array.

## 📊 Example
```
Input: arr[] = {1, 8, 7, 56, 90}
Output: 90
```

## 🚀 Approach
1. Initialize a variable `largest` with smallest possible integer value (INT_MIN)
2. Iterate through the array ➡️
3. For each element, if it's greater than `largest`, update `largest` ⬆️
4. Return the `largest` value ✅

## 💻 Solution
```cpp
class Solution {
public:
    int largest(vector<int> &arr) {
        int largest = INT_MIN;  // 📉 Start with minimum value
        
        for(auto elem: arr) {   // 🔄 Iterate through array
            if(elem > largest) largest = elem;  // 📈 Update if larger found
        }
        
        return largest;  // 🎯 Return result
    }
};
```

## ⚡ Time and Space Complexity
- Time Complexity: $O(n)$ ⏱️
- Space Complexity: $O(1)$ 💾

## 2. Find Second Largest Element

### 📝 Problem Statement
Given an array `arr[]` of size `N`, find the second largest element in the array.

### 📊 Example
```
Input: arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
```

### 🚀 Approach (Two-Pass Solution)
1. First Pass: Find the largest element ➡️
2. Second Pass: Find largest element smaller than the largest ⬇️
3. Handle edge cases (no second largest exists) ⚠️

### 💻 Solution
```cpp
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN;  // 📈 Track largest element
        
        // First pass: Find largest element
        for(auto elem: arr) {   // 🔄 First traversal
            if(elem > largest) largest = elem;
        }
        
        int second_largest = INT_MIN;  // 📊 Track second largest
        
        // Second pass: Find second largest
        for(auto elem: arr) {   // 🔄 Second traversal
            if(elem != largest) {  // 🎯 Skip largest element
                if(elem > second_largest) second_largest = elem;
            }
        }
        
        return second_largest == INT_MIN ? -1 : second_largest;  // ✅ Return result
    }
};
```

### ⚡ Time and Space Complexity
- Time Complexity: $O(n)$ ⏱️ (Two passes)
- Space Complexity: $O(1)$ 💾

### 🔗 Links
- [GeeksForGeeks Problem](https://www.geeksforgeeks.org/problems/second-largest3735/1)


### 🚀 Optimized Approach (One-Pass Solution)
1. Initialize `largest` with first element and `second_largest` with INT_MIN ➡️
2. For each element starting from index 1:
   - If current > largest: Update both largest and second_largest ⬆️
   - If current < largest but > second_largest: Update second_largest 📈
3. Handle edge case (no second largest exists) ⚠️

### 💻 Optimized Solution
```cpp
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int largest = arr[0];           // 📊 Start with first element
        int second_largest = INT_MIN;    // 📉 Initialize second largest
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > largest) {       // 📈 Found new largest
                second_largest = largest; // 🔄 Current largest becomes second
                largest = arr[i];         // ⬆️ Update largest
            }
            else if(arr[i] < largest && arr[i] > second_largest) {
                second_largest = arr[i];  // 📈 Update second largest
            }
        }
        
        return second_largest == INT_MIN ? -1 : second_largest;  // ✅ Return result
    }
};
```

### ⚡ Optimized Complexity
- Time Complexity: $O(n)$ ⏱️ (Single pass)
- Space Complexity: $O(1)$ 💾

### 📊 Comparison with Two-Pass
| Aspect | Two-Pass | One-Pass |
|--------|----------|----------|
| Time Complexity | $O(n)$ (2 passes) | $O(n)$ (1 pass) |
| Array Traversals | 2 | 1 |


> 🎯 The one-pass solution is more efficient as it requires only a single traversal of the array.

## 📋 Problems Table

| No. | Problem | Status | Solution |
|-----|---------|--------|-----------|
| 1 | [Find Largest Element in Array](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1) | $✅$ Solved | Above |
| 2 | [Find Second Largest Element](https://www.geeksforgeeks.org/problems/second-largest3735/1) | $✅$ Solved | Above |
| 3 | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) | $✅$ Solved | [Solution](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/6740168/1752-check-if-array-is-sorted-and-rotate-upf0/) |
| 4 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/6749808/remove-duplicates-from-sorted-array-leetcode-26-clean-in-place-with-two-pointers/) |
| 5 | [Rotate Array](https://leetcode.com/problems/rotate-array/description/) | ⏳ Unsolved | - |
| 6 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/move-zeroes/solutions/6749908/move-zeroes-two-pointer-swap-approach-by-s5im/) |
| 7 | [Union Of Sorted Arrays](https://www.codechef.com/practice/course/tcs-nqt-questions/TCSNQTC/problems/TCSNQTCP08) | ✅ Solved | [Solution](../Arrays/sols/7_union_of_sorted_arrays.md) |
| 8 | [Missing Number](https://leetcode.com/problems/missing-number/) | ✅ Solved | [Solution](https://leetcode.com/problems/missing-number/solutions/6750120/missing-number-using-sum-formula-o-n-time-o-1-space/) |
| 9 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/max-consecutive-ones/solutions/6750207/max-1s-in-a-row-fast-clean-solution-by-k-3u3y/) |
| 10 | [Single Number](https://leetcode.com/problems/single-number/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/single-number/solutions/6750234/unique-element-finder-with-bitwise-xor-t-qz9q/) |
| 11 | [Longest Sub-Array with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) | ⏳ Unsolved | - |
| 12 | [Two Sum](https://leetcode.com/problems/two-sum/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/two-sum/solutions/6674442/c-solution-two-sum-with-sorting-two-pointers-beats-100/) |
| 13 | [Sort Colors](https://leetcode.com/problems/sort-colors/description/) | ⏳ Unsolved | - |
| 14 | [Majority Element](https://leetcode.com/problems/majority-element/) | ✅ Solved | [Solution](https://leetcode.com/problems/majority-element/solutions/6753170/title-boyer-moore-voting-algorithm-on-ti-vd7k/) |
| 15 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) | ⏳ Unsolved | - |
| 16 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/6753347/best-time-to-buy-and-sell-stock-greedy-o-rz5h/) |
| 17 | [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/6753497/alternate-positive-and-negative-numbers-xn6z1/) |
| 18 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | ⏳ Unsolved | - |
| 19 | [Leaders in an Array](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1) | ✅ Solved| [solution](../Arrays/sols/19_leaders_in_array.md) |
| 20 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/) | ⏳ Unsolved | - |
| 21 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/) | ⏳ Unsolved | - |
| 22 | [Rotate Image](https://leetcode.com/problems/rotate-image/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/rotate-image/solutions/6755365/inplace-rotate-image-90-degrees-clockwis-fkif/) |
| 23 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/) | ⏳ Unsolved | - |
| 24 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/subarray-sum-equals-k/solutions/6755785/leetcode-560-subarray-sum-equals-k-brute-niei/) |
| 25 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/) | ⏳ Unsolved | - |
| 26 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/description/) | ⏳ Unsolved | - |
| 27 | [3Sum](https://leetcode.com/problems/3sum/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/3sum/solutions/6677515/3sum-zero-finder-c-beats-95-easy-to-understand/) |
| 28 | [4Sum](https://leetcode.com/problems/4sum/description/) | ⏳ Unsolved | - |
| 29 | [Largest subarray with 0 sum](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1) | ✅ Solved | [Solution](../Arrays/sols/29.md) |
| 30 | [Count Subarrays with Given XOR](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1) | ✅ Solved | [Solution](../Arrays/sols/30.md) |
| 31 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/merge-intervals/solutions/6769858/c-no-redundant-checks-on-log-n-explained-51i2/) |
| 32 | [Merge Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/description/) | ✅ Solved | [Solution](https://leetcode.com/problems/merge-sorted-array/solutions/6772747/merge-sorted-array-in-place-from-the-end-hmk6/) |
| 33 | [Find Missing and Repeating](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1) | ⏳ Unsolved | - |

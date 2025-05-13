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


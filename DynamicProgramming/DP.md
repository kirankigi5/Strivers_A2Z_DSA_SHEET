# Dynamic Programming

> ### *"Those who cannot remember the past are condemned to repeat it."*
> **- George Santayana**

## Types of Dynamic Programming

1. **Memoization (Top-Down):**
    - Recursively solve subproblems
    - Store results in a cache/table
    - Check cache before computation

2. **Tabulation (Bottom-Up):**
    - Iteratively solve subproblems
    - Fill results in a table
    - Build solution from smallest to largest

3. **Space-Optimized:**
    - Optimize space complexity
    - Usually modify tabulation
    - Keep only necessary states

Each type has its own advantages:
- Memoization: Easier to implement, naturally recursive
- Tabulation: Better space complexity, no recursion overhead
- Space-Optimized: Best memory usage, but can be complex

## Overlapping Subproblems

Overlapping subproblems occur when a recursive algorithm visits the same subproblems multiple times. This is one of the key characteristics that makes a problem suitable for dynamic programming.

### Example: Fibonacci Sequence
```cpp
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1)
│   │   │   └── fib(0)
│   │   └── fib(1)
│   └── fib(2)
│       ├── fib(1)
│       └── fib(0)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1)
    │   └── fib(0)
    └── fib(1)
```

### Observations
1. Notice how `fib(3)`, `fib(2)`, `fib(1)`, and `fib(0)` are calculated multiple times
2. Without DP (Basic Recursion):
   - Time Complexity: $O(2^n)$
   - Each value recalculated multiple times

### Solution Using DP
1. **Memoization**: Store results in a cache (top-down)
   - Calculate once, reuse many times
   - Time Complexity reduced to $O(n)$

2. **Tabulation**: Build results iteratively (bottom-up)
   - Avoid recursion altogether
   - Fill table from smallest to largest subproblem

> Note: Not all recursive problems have overlapping subproblems. For example, merge sort divides the array into distinct subarrays that don't overlap.

## Example: Fibonacci Number

Problem: Given `n`, calculate the nth Fibonacci number.

### 0. Normal Recursion Approach
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};
```
- Time: $O(2^n)$ - exponential due to repeated calculations
- Space: $O(n)$ - recursion stack depth

### 1. Memoization Approach
```cpp
class Solution {
    unordered_map<int, int> memo;
public:
    int fib(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];
        return memo[n] = fib(n-1) + fib(n-2);
    }
};
```
- Time: $O(n)$
- Space: $O(n)$

### 2. Tabulation Approach
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```
- Time: $O(n)$
- Space: $O(n)$

### 3. Space-Optimized Approach
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```
- Time: $O(n)$
- Space: $O(1)$


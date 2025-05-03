# Dynamic Programming

> ### *"Those who cannot remember the past are condemned to repeat it."*
> ***- George Santayana***

## Types of Dynamic Programming

1. **Memoization (Top-Down):**
    - Recursively solve subproblems
    - Store results in a cache/table
    - Check cache before computation

## Overlapping Subproblems in Fibonacci

A classic example of overlapping subproblems is calculating Fibonacci numbers. The Fibonacci sequence is defined as:
- $F(0) = 0$
- $F(1) = 1$
- $F(n) = F(n-1) + F(n-2)$ for $n > 1$

### Example: $fib(5)$
When calculating $fib(5)$, we need $fib(4)$ and $fib(3)$. To get $fib(4)$, we need $fib(3)$ and $fib(2)$, and so on. This creates a tree of recursive calls where many calculations are repeated:

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

3. **Space Optimization**: Further improve memory usage
    - Keep only necessary previous values
    - Reduce space complexity to $O(1)$
    - Perfect for problems with dependencies on just recent states

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


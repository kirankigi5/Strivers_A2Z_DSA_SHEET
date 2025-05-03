# Dynamic Programming

> ### *"Those who cannot remember the past are condemned to repeat it."*
> ***- George Santayana***

## Understanding the Need for DP

### Recursive Solution Problems
Let's understand why we need DP using the Fibonacci sequence example:
- $F(0) = 0$
- $F(1) = 1$
- $F(n) = F(n-1) + F(n-2)$ for $n > 1$

#### Basic Recursive Approach
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

#### The Problem: Overlapping Subproblems
When calculating $fib(5)$, see how many calculations are repeated:
```txt
                                fib(5)
                    ┌────────────┴─────────────────┐
                  fib(4)                         fib(3)
            ┌────────┴────────┐              ┌──────┴──────┐
          fib(3)           fib(2)         fib(2)        fib(1)
      ┌─────┴─────┐     ┌────┴────┐     ┌────┴────┐
    fib(2)     fib(1) fib(1)  fib(0)   fib(1) fib(0)
 ┌────┴────┐
fib(1)  fib(0)
```
<iframe width="560" height="315" src="https://www.youtube.com/embed/mrPoy2-i32s?si=OfgNvFhi3kSq5xAh" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


- This recursive tree shows how `fib(2)` is calculated 3 times
- `fib(1)` is calculated 5 times
- `fib(0)` is calculated 3 times

### Observations
1. Notice how `fib(3)`, `fib(2)`, `fib(1)`, and `fib(0)` are calculated multiple times
2. This leads to exponential time complexity $O(2^n)$
3. We need a way to store and reuse these calculated values

## Dynamic Programming Solutions

### 1. Memoization (Top-Down)
Store results in cache to avoid recalculation
```cpp
class Solution {
private:
    int fibHelper(int n, vector<int>& memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = fibHelper(n-1, memo) + fibHelper(n-2, memo);
    }
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fibHelper(n, memo);
    }
};
```
- Time: $O(n)$
- Space: $O(n)$

### 2. Tabulation (Bottom-Up)
Build solution iteratively from smaller subproblems
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

### 3. Space Optimization
Keep only necessary previous states
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

> Note: Not all recursive problems have overlapping subproblems. For example, merge sort divides the array into distinct subarrays that don't overlap.


# RECURSION

## Definition

Recursion is a programming concept where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems. A recursive function has two main components:

| Component | Description |
|-----------|-------------|
| **1. Base case(s)** | - The condition(s) that stop the recursion<br>- Returns a value without making another recursive call<br>- Prevents infinite recursion |
| **2. Recursive case(s)** | - The function calls itself with modified parameters<br>- Makes progress toward the base case<br>- Breaks down the problem into smaller instances |
| **Key characteristics** | - Must eventually reach a base case to terminate<br>- Can often replace loops<br>- May consume more memory due to call stack usage |

## Stack Space and Stack Overflow

### Stack Space in Recursion
```cpp
void recursiveFunction(int n) {
    // Each call creates a new stack frame
    if (n == 0) return; // Base case
    recursiveFunction(n - 1); // Recursive call
}

int main() {
    recursiveFunction(10);
}
```
- Each recursive call adds a new frame to the call stack
- Stack frame contains: local variables, parameters, return address
- Memory is allocated in stack for each function call

### Stack Overflow
```cpp
void countDown(int n) {
    // Missing base case
    printf("%d ", n);
    countDown(n - 1); // Will continue indefinitely
}

int main() {
    countDown(5); // Will eventually cause stack overflow
    return 0;
}
```
- Occurs when recursive depth exceeds available stack memory
- Common causes:
  - Missing base case (as shown above)
  - Too many recursive calls
  - Large local variables in recursive functions



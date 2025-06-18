## 💻 Problem Statement

Given an array `arr`, reverse it **in-place** using **recursion** — without using loops or extra space.

---

## 🧠 Intuition

We’ll use a classic **two-pointer** approach:

* One pointer starts at the **left**, and the other at the **right**.
* Swap the elements.
* Move `left++` and `right--`, and repeat **recursively**.

📌 Base case: When `left >= right`, stop recursion.

---

## 🔍 Dry Run

For input: `arr = [1, 2, 3, 4, 5]`

```
swapIndices(0, 4) → swap 1 and 5 → [5, 2, 3, 4, 1]
swapIndices(1, 3) → swap 2 and 4 → [5, 4, 3, 2, 1]
swapIndices(2, 2) → base case → done
```

🖨️ Final Output: `[5, 4, 3, 2, 1]`

---

## ✅ Code Walkthrough

```cpp
class Solution {
  public:
    // Helper function to swap values at left and right recursively
    void swapIndices(int left, int right, vector<int> &arr)
    {
        if (left >= right) return;         // 🛑 Base case
        
        swap(arr[left], arr[right]);       // 🔄 Swap the two ends
        
        swapIndices(left + 1, right - 1, arr); // 🔁 Recurse inward
    }

    // Main function that initiates the recursion
    void reverseArray(vector<int> &arr) {
        swapIndices(0, arr.size() - 1, arr);
    }
};
```

---

## ⏱ Time and Space Complexity

| Complexity | Value        |
| ---------- | ------------ |
| 🕒 Time    | O(n)         |
| 🧠 Space   | O(n) (stack) |

Because each recursion frame processes one swap, and the depth is `n/2` → stack space is `O(n)`.

---

## 🧠 Concept Reinforcement

* This pattern is very helpful in **palindrome checking**, **string/array reversal**, and **in-place modifications**.
* It strengthens your grasp on **two-pointer recursion** 🔁➡️⬅️



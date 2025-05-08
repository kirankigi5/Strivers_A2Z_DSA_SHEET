## 💻 Problem Statement

Given an integer `N`, print numbers from `N` to `1` in decreasing order using **recursion**.
No loops allowed! 🔁❌

---

## 🧠 Intuition

In contrast to printing `1 to N`, this time we:

* **Print first**, then recursively go down. 📉
* We **do the work before the recursive call**.

---

## 📦 Dry Run Example

Say `N = 3`:

```
printTill1(3)
├── print 3
├── printTill1(2)
│   ├── print 2
│   ├── printTill1(1)
│   │   ├── print 1
│   │   └── printTill1(0) → return
```

🖨️ Output: `3 2 1`

---

## ✅ Code

```cpp
class Solution {
  public:
    void printTill1(int n) {
        if (n == 0) return;     // 🛑 Base case: nothing to print

        cout << n << " ";       // 🖨️ Print before recursive call

        printTill1(n - 1);      // 🔁 Recursive call to print next number
    }
};
```

---

## ✅ Time and Space Complexity

| Complexity | Value                     |
| ---------- | ------------------------- |
| 🕒 Time    | O(n)                      |
| 🧠 Space   | O(n)  (due to call stack) |

---


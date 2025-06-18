## 💻 Problem Statement

Given an integer `N`, print numbers from `1` to `N` in increasing order using **recursion**.
No loops allowed! 🔁❌

---

## 🧠 Intuition

We're using **recursion** to handle printing numbers from `1` to `N`.

* Think of recursion as stacking tasks 📚 — we delay printing until we reach the base case.
* Once the base case is hit (`n == 0`), the stack **unwinds** and we print numbers while coming back up! 🔁⬆️

---

## 📦 Dry Run Example

Say `N = 3`:

```cpp
printTillN(3)
├── printTillN(2)
│   ├── printTillN(1)
│   │   └── printTillN(0) → return (base case)
│   │   └── print 1
│   └── print 2
└── print 3
```

🖨️ Output: `1 2 3`

---

## 🧾 Code Walkthrough

```cpp
void printTillN(int n) {
    if (n == 0) return; // 🛑 Base case: stop recursion when n == 0
    
    printTillN(n - 1);  // 🧗 Recursive call: go till 1 before printing anything
    
    cout << n << " ";   // 🖨️ Print on the way back up!
}
```

---

## ✅ Time and Space Complexity

| Complexity | Value                               |
| ---------- | ----------------------------------- |
| 🕒 Time    | O(n)                                |
| 🧠 Space   | O(n)  (due to recursive call stack) |

---



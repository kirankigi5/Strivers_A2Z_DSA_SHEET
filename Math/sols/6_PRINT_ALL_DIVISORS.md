
---

## ✅ **Optimal Approach**

To find all divisors of a number `n`, a naive solution would iterate from `1` to `n`, resulting in **O(n)** time. 😩

But we can do better! Here's how:

* A divisor `d` of `n` always comes with a **pair** `n/d`.
* So we only need to loop from `1` to `√n`, and for each divisor found in that range, we can infer its **complementary divisor**.
* This makes the time complexity **O(√n)**. 🚀

We also want to print the divisors **in sorted order**, which is a challenge because:

* Small divisors come first (`1, 2, 4`)
* But their corresponding pairs (`n/4, n/2, n`) should come **later**

To solve this:

* Use a **queue** for smaller divisors (`1 → √n`) ➡️ printed **first**
* Use a **stack** for their larger pair divisors (`n/i`) ➡️ printed **afterwards in reverse order**

This keeps the output sorted with **no sorting step needed**.

---

## 💻 **Optimal Code**

```cpp
class Solution {
  public:
    void print_divisors(int n) {
        queue<int> smallerDivs;  // To store smaller divisors in order (FIFO) 🧾
        stack<int> largerDivs;   // To store larger divisors in reverse (LIFO) 🔁

        int sqrt_n = sqrt(n);    // Precompute square root to avoid recalculating
        
        for(int i = 1; i < sqrt_n; i++) {
            if(n % i == 0) {
                smallerDivs.push(i);        // i is a divisor
                largerDivs.push(n / i);     // n / i is its pair
            }
        }

        // Handle the square root separately (only push once)
        if(n % sqrt_n == 0) {
            smallerDivs.push(sqrt_n);
        }


        // Print all smaller divisors in order 📤
        while(!smallerDivs.empty()) {
            cout << smallerDivs.front() << " ";
            smallerDivs.pop();
        }

        // Print all larger divisors in reverse (from the stack) 🔁
        while(!largerDivs.empty()) {
            cout << largerDivs.top() << " ";
            largerDivs.pop();
        }
    }
};
```

---

## 🔍 **Time & Space Complexity**

* **Time Complexity**:
  `O(√n)` – You only iterate up to `√n`.

* **Space Complexity**:
  `O(√n)` – In the worst case (when `n` is prime), you might store up to `√n` divisors in total between the queue and stack.

---

## 🧠 TL;DR

| 🧾 Metric                    | Value                                         |
| ---------------------------- | --------------------------------------------- |
| **Time**                     | `O(√n)` ✅                                     |
| **Space**                    | `O(√n)` ✅                                     |
| **Sorted Output?**           | Yes, using queue + stack combo ✔️             |
| **Handles perfect squares?** | Yes, with conditional check for duplicates 🔄 |


---

## 🧪 Example 1: `n = 36`

We'll find all divisors of `36` and print them in **sorted order**.

### ✅ Divisors of 36:

`1, 2, 3, 4, 6, 9, 12, 18, 36`

### 🔁 Loop from 1 to √36 (i.e., 1 to 6)

For each `i`:

* If `36 % i == 0`, then both `i` and `36/i` are divisors.
* Add `i` to the **queue** (for ascending order).
* Add `36/i` to the **stack** (for reverse order).

### 🧮 Step-by-step:

| i | Condition               | Action                                                 |
| - | ----------------------- | ------------------------------------------------------ |
| 1 | ✅ 36 % 1 = 0            | `queue: [1]`, `stack: [36]`                            |
| 2 | ✅                       | `queue: [1, 2]`, `stack: [36, 18]`                     |
| 3 | ✅                       | `queue: [1, 2, 3]`, `stack: [36, 18, 12]`              |
| 4 | ✅                       | `queue: [1, 2, 3, 4]`, `stack: [36, 18, 12, 9]`        |
| 5 | ❌                       | —                                                      |
| 6 | ✅ (Perfect square case) | `queue: [1, 2, 3, 4, 6]` (don’t push 6 again to stack) |

Now print:

1. **From queue**: → `1 2 3 4 6`
2. **From stack**: → `9 12 18 36`

✅ Final Output:
`1 2 3 4 6 9 12 18 36`

---

## 🧪 Example 2: `n = 30`

### ✅ Divisors of 30:

`1, 2, 3, 5, 6, 10, 15, 30`

### √30 ≈ 5.47 ⇒ loop i = 1 to 5

| i | Condition | Action                                          |
| - | --------- | ----------------------------------------------- |
| 1 | ✅         | `queue: [1]`, `stack: [30]`                     |
| 2 | ✅         | `queue: [1, 2]`, `stack: [30, 15]`              |
| 3 | ✅         | `queue: [1, 2, 3]`, `stack: [30, 15, 10]`       |
| 4 | ❌         | —                                               |
| 5 | ✅         | `queue: [1, 2, 3, 5]`, `stack: [30, 15, 10, 6]` |

Now print:

1. **From queue**: → `1 2 3 5`
2. **From stack**: → `6 10 15 30`

✅ Final Output:
`1 2 3 5 6 10 15 30`

---

## 📦 Recap: How `queue` & `stack` help

| Structure    | Purpose                      | Behavior                                      |
| ------------ | ---------------------------- | --------------------------------------------- |
| `queue<int>` | Store small divisors (`i`)   | First In First Out (FIFO) – ascending order ✅ |
| `stack<int>` | Store large divisors (`n/i`) | Last In First Out (LIFO) – descending order ✅ |

Together, they allow you to **print all divisors in sorted order** without needing to sort manually.

---


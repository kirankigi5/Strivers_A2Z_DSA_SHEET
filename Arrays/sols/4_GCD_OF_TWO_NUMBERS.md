## 🧠 **Intuition**

To find the **Greatest Common Divisor (GCD)** of two numbers `a` and `b`, we want the largest number that divides both.

There are **two popular approaches**:

1. 🧮 **Factorization Method** — check all divisors of the smaller number and see which ones also divide the other number.
2. ⚡ **Euclidean Algorithm** — a faster and more elegant approach using the property:
   $\text{gcd}(a, b) = \text{gcd}(b, a \% b)$

---

## 🛠️ **Approach**

### ✅ Factorization-Based GCD

* Loop from `1` to `sqrt(a)` and find all factors of `a`.
* For each factor (both `i` and `a/i`), check if it divides `b`.
* Track the **largest such divisor** — that’s your GCD.

### ⚡ Standard Method: Euclidean Algorithm

* Repeatedly assign `a = b` and `b = a % b` until `b == 0`.
* The last non-zero `a` is the GCD.
* Very fast even for large inputs.

---

## 🧮 **Code (Both Approaches)**

### 💡 Factorization-Based Method

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        int gcd = 1;

        for(int i = 1; i <= sqrt(a); i++) {
            if(a % i == 0) {
                int small_factor = i;
                int big_factor = a / i;

                if(b % big_factor == 0) {
                    gcd = max(gcd, big_factor);
                } else if(b % small_factor == 0) {
                    gcd = max(gcd, small_factor);
                }
            }
        }

        return gcd;
    }
};
```

---

### ⚡ Euclidean Algorithm Version

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
```

---

## ⏱️ **Complexity Comparison**

| Approach               | Time Complexity       | Space Complexity | Comments                                         |
| ---------------------- | --------------------- | ---------------- | ------------------------------------------------ |
| 🧮 Factorization-Based | $O(\sqrt{a})$         | $O(1)$           | Good for learning, but slower for large inputs   |
| ⚡ Euclidean Algorithm  | $O(\log(\min(a, b)))$ | $O(1)$           | Industry-standard, fast, and always preferred 💯 |


---

## 🔥 **U did it!** 💪

<a href="https://ibb.co/pV23Gs3"><img src="https://i.ibb.co/dCBQ13Q/upvote-final.png" alt="upvote-final" border="0"></a>


## 🧠 **Intuition**

A **prime number** is a number greater than `1` that has **no positive divisors other than 1 and itself**. So, to check if a number `n` is prime, we must verify that it is **not divisible** by any number from `2` to `√n`. ✅

---

## 🛠️ **Approach**

1. **Start from 2** up to `sqrt(n)`.
2. For each number `i`, check if `n % i == 0`.
3. If we find **any such divisor**, return `false` — `n` is not prime. ❌
4. If no such divisor is found, return `true` — it's a prime number. ✔️

---

## 🔍 **Time and Space Complexity**

* **Time Complexity:**
  $O(\sqrt{n})$
  We only loop till the square root of `n` because any divisor `> √n` would already have a matching pair `< √n`.

* **Space Complexity:**
  $O(1)$
  We use constant space — just a few variables.

---

## 💻 **Code**

```cpp
class Solution {
  public:
    bool isPrime(int n) {
        // Special case: Numbers <= 1 are not prime ❌
        if(n <= 1) return false;

        // ✅ Loop from 2 to sqrt(n)
        for(int i = 2; i <= sqrt(n); i++)
        {
            // If 'n' is divisible by 'i', it's not a prime number 🚫
            if(n % i == 0)
            {
                return false;
            }
        }
        
        // If no divisors found, it's prime ✔️
        return true;
    }
};
```

---

## 🧪 Example

Let’s say `n = 29`

* We loop `i = 2` to `5` (since √29 ≈ 5.38)
* 29 % i ≠ 0 for all `i`, so it’s a prime ✅


---

## 🔥 **U did it** 💡

<a href="https://ibb.co/pV23Gs3"><img src="https://i.ibb.co/dCBQ13Q/upvote-final.png" alt="upvote-final" border="0"></a>



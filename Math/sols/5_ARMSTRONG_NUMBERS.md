## 🧠 **Intuition**

An **Armstrong number** (also known as a narcissistic number) is a number that is equal to the **sum of the cubes of its digits**.
Since the input is guaranteed to be a **3-digit number** (as per constraints in problems like this), we can directly extract each digit and check if:

> **digit₁³ + digit₂³ + digit₃³ == number**

---

## 🛠️ **Approach**

🔢 Let's extract each digit:

1. Take the last digit using `n % 10`.
2. Remove the last digit by dividing `n` by 10.
3. Repeat until all 3 digits are extracted.

💡 Compute the **sum of cubes** of the digits and compare it with the original number.

---

## 🔍 **Complexity**

* **Time Complexity**: `O(1)`
  We're working with a constant number of digits (3), so the operations are fixed.

* **Space Complexity**: `O(1)`
  We're using only a few integer variables.

---

## 💻 **Code**

```cpp
class Solution {
  public:
    bool armstrongNumber(int n) {
        int original = n;  // Keep original number to compare later

        // Extract digits 🔍
        int digit1 = n % 10;
        n /= 10;

        int digit2 = n % 10;
        n /= 10;

        int digit3 = n;

        // Calculate sum of cubes 🎲
        int sum = pow(digit1, 3) + pow(digit2, 3) + pow(digit3, 3);

        // Return if sum matches original number ✅
        return sum == original;
    }
};
```

---

## 🧪 **Examples**

* Input: `153`
  `1³ + 5³ + 3³ = 1 + 125 + 27 = 153` ✅

* Input: `370`
  `3³ + 7³ + 0³ = 27 + 343 + 0 = 370` ✅

* Input: `123`
  `1³ + 2³ + 3³ = 1 + 8 + 27 = 36` ❌

---

## 🔥 **U did it!** 

<a href="https://ibb.co/pV23Gs3"><img src="https://i.ibb.co/dCBQ13Q/upvote-final.png" alt="upvote-final" border="0"></a>

---

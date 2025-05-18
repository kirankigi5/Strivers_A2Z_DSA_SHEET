## 💥 Problem: Leaders in an Array

🔹 A **leader** in an array is an element that is **greater than or equal to all elements to its right**.
🔹 The **rightmost** element is always a leader.

---

## 🧠 Approach: Stack for Reverse Traversal

We move **right-to-left** ⬅️, and:

* Push leaders into a **stack** 📦 as we go.
* Pop them later to return them in **left-to-right** ➡️ order.

---

## ✅ C++ Code 

```cpp
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        stack<int> st; // 📦 to store leaders in reverse order

        // 🟢 The last element is always a leader
        st.push(arr[n - 1]);

        // 🔁 Traverse from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] >= st.top()) {
                st.push(arr[i]); // 💪 Found a leader!
            }
        }

        // 🔄 Reverse the stack into a vector
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top()); // 📥 Add to result
            st.pop();                   // 🚮 Pop from stack
        }

        return result; // 🚀 Return all leaders in correct order
    }
};
```

---

## ⏱️ Time Complexity

* `O(n)` — One pass through the array 🏃‍♂️

## 📦 Space Complexity

* `O(n)` — For the stack and result vector 🧠

---

## 🧪 Example

```cpp
Input:  [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
```

---

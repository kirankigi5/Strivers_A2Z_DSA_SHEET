
---

### 🔍 Problem Statement

Given two **sorted arrays**, return their **union** as a new sorted array that contains **only unique elements** from both arrays.

📥 **Input:**

* Two sorted arrays `arr1` and `arr2`, of sizes `n` and `m`.

📤 **Output:**

* A sorted array containing the union of both arrays **without duplicates**.

---

### 💡 Intuition

Since the arrays are already **sorted**, we can use the **two-pointer technique** to efficiently merge both arrays while skipping duplicates.

This is similar to the merge step in **Merge Sort**, but with an added condition to skip inserting the same value twice.

---

### ⚙️ Approach

1. Initialize two pointers `ptr1 = 0` and `ptr2 = 0`.
2. Compare `arr1[ptr1]` and `arr2[ptr2]`:

   * Insert the smaller one if it's not already added to the result.
   * If they’re equal, insert it once and advance both pointers.
3. Skip inserting any element that is the **same as the last inserted element** (avoid duplicates).
4. After one array is fully traversed, continue processing the remaining elements in the other array (again, skipping duplicates).

---

### ⏱️ Time & Space Complexity

| Metric              | Value                                                                                  |
| ------------------- | -------------------------------------------------------------------------------------- |
| 🕒 Time Complexity  | `O(n + m)` – each element is processed once.                                           |
| 🧠 Space Complexity | `O(n + m)` – in the worst case (no duplicates), all elements are stored in the result. |

---

### ✅ Example

**Input:**

```
arr1 = [1, 2, 2, 3, 4]
arr2 = [2, 3, 5]
```

**Output:**

```
[1, 2, 3, 4, 5]
```

---

### 🧾 Code 

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
🔁 Two-pointer method to find union of two sorted arrays
*/

vector<int> findUnion(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    vector<int> unionArr;
    int ptr1 = 0, ptr2 = 0;

    // 🚶 Traverse both arrays
    while (ptr1 < n && ptr2 < m) {
        if (unionArr.empty() || (unionArr.back() != arr1[ptr1] && unionArr.back() != arr2[ptr2])) {
            if (arr1[ptr1] < arr2[ptr2]) {
                unionArr.emplace_back(arr1[ptr1]);
                ptr1++;
            } else if (arr1[ptr1] > arr2[ptr2]) {
                unionArr.emplace_back(arr2[ptr2]);
                ptr2++;
            } else {
                unionArr.emplace_back(arr1[ptr1]); // common element
                ptr1++;
                ptr2++;
            }
        } else {
            // 🧼 Skip duplicates
            if (unionArr.back() == arr1[ptr1]) ptr1++;
            if (unionArr.back() == arr2[ptr2]) ptr2++;
        }
    }

    // 🧹 Clean up remaining elements in arr1
    while (ptr1 < n) {
        if (unionArr.empty() || unionArr.back() != arr1[ptr1]) {
            unionArr.emplace_back(arr1[ptr1]);
        }
        ptr1++;
    }

    // 🧹 Clean up remaining elements in arr2
    while (ptr2 < m) {
        if (unionArr.empty() || unionArr.back() != arr2[ptr2]) {
            unionArr.emplace_back(arr2[ptr2]);
        }
        ptr2++;
    }

    return unionArr;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n), arr2(m);

        for (int i = 0; i < n; i++) cin >> arr1[i];
        for (int i = 0; i < m; i++) cin >> arr2[i];

        vector<int> result = findUnion(n, m, arr1, arr2);

        for (auto &val : result) cout << val << " ";
        cout << endl;
    }

    return 0;
}
```





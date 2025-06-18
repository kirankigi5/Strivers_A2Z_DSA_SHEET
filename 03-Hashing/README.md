# 🔢 Hashing: Frequency Counting Approaches

## 📌 Overview

Hashing is a common technique for counting the frequency of elements in an array or stream of data. The choice of data structure depends on:

* Size and range of input values
* Need for fast queries
* Memory constraints
* Order of keys

---

## ⚙️ Frequency Counting Techniques

### 1. **Array / Vector (Brute Force)**

> Best when values are integers in a small, known range (e.g., 0 to 10⁶)

```cpp
vector<int> freq(1001, 0);  // Pre-allocate space
for (int num : arr) {
    freq[num]++;  // Count frequency
}
int frequency = freq[number];  // Query in O(1)
```

**✅ Pros:**

* Very fast queries: **O(1)**
* Simple and cache-friendly
* Low overhead if data is dense

**❌ Cons:**

* Only works for **small, known ranges**
* **Wastes space** for sparse data
* Limited by stack/global memory size

---

### 2. **Ordered Map (`std::map`)**

> Suitable for any value range; provides ordered keys

```cpp
map<int, int> freq;
for (int num : arr) {
    freq[num]++;
}
int frequency = freq[number];  // Query in O(log n)
```

**✅ Pros:**

* Works for **any data range**
* Maintains **sorted keys**
* Good for problems needing ordered traversal

**❌ Cons:**

* Slower queries: **O(log n)**
* Higher memory overhead (tree structure)

---

### 3. **Unordered Map (`std::unordered_map`)**

> Best for large, dynamic, and unordered datasets

```cpp
unordered_map<int, int> freq;
for (int num : arr) {
    freq[num]++;
}
int frequency = freq[number];  // Query in O(1) average
```

**✅ Pros:**

* **Fast queries (O(1)** average)
* Handles **any value range**
* No need to predefine size

**❌ Cons:**

* **Worst-case** query time: O(n) due to collisions
* Memory overhead from hashing
* No ordered iteration

---

## 🧠 Choosing the Right Data Structure

| Data Structure           | Use When...                                                                                             |
| ------------------------ | ------------------------------------------------------------------------------------------------------- |
| **Array / Vector**       | • Values in a **small, known range**<br>• Need **fastest queries**<br>• Can allocate memory efficiently |
| **`std::map`**           | • Values in **any range**<br>• Need **ordered traversal**<br>• Can tolerate slower lookups              |
| **`std::unordered_map`** | • Values in **any range**<br>• Need **fast average lookups**<br>• No need for order                     |

---

## 🧮 Array Size Limits in C++

| Context         | `int[]` Max Size | `bool[]` Max Size |
| --------------- | ---------------- | ----------------- |
| Inside `main()` | \~10⁶            | \~10⁷             |
| Global scope    | \~10⁷            | \~10⁸             |


---

## ✅ Summary Table

| Approach                 | Query Time             | Ordered Keys | Range Flexibility  | Memory Usage   | Use Case                   |
| ------------------------ | ---------------------- | ------------ | ------------------ | -------------- | -------------------------- |
| **Array / Vector**       | O(1)                   | ❌            | Small, fixed range | Low (if dense) | Counting small integers    |
| **`std::map`**           | O(log n)               | ✅            | Any                | High           | Ordered frequencies        |
| **`std::unordered_map`** | O(1) avg<br>O(n) worst | ❌            | Any                | High           | Fast lookups without order |

---


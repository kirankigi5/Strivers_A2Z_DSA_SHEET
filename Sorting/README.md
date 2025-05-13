# 🔄 Sorting Algorithms

| Algorithm 🔄 | Time Complexity | Space Complexity | Description |
|-----------|----------------|------------------|-------------|
| Selection Sort 🔍 | $O(n^2)$ | $O(1)$ | Simple sorting algorithm based on repeatedly finding minimum element ⬇️ |
| Bubble Sort 🫧 | $O(n^2)$ | $O(1)$ | Repeatedly swaps adjacent elements if they are in wrong order ↔️ |
| Insertion Sort 📥 | $O(n^2)$ | $O(1)$ | Builds final sorted array one item at a time ➡️ |
| Merge Sort 🔄 | $O(n \log n)$ | $O(n)$ | Divide and conquer algorithm that recursively breaks down array 🔀 |
| Quick Sort ⚡ | $O(n \log n)$ average, $O(n^2)$ worst | $O(\log n)$ | Recursive divide and conquer algorithm using pivot element 📊 |

## 🔍 Selection Sort
```cpp
void selectionSort(vector<int> &arr) {
    // Iterate through array (except last element)
    for(int i = 0; i < arr.size() - 1; i++) {
        int min_idx = i;  // 📌 Assume current index has minimum value
        
        // 🔍 Find minimum element in unsorted portion
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;  // 📝 Update minimum index if found
            }
        }
        
        swap(arr[i], arr[min_idx]);  // 🔄 Place minimum element in position
    }
}
```
[Practice on GeeksForGeeks](https://www.geeksforgeeks.org/problems/selection-sort/1)

## 🫧 Bubble Sort
```cpp
void bubbleSort(vector<int>& arr) {
    for(int i = arr.size() - 2; i >= 0; i--) {
        bool swaps = false;  // 🚩 Flag to check if any swaps occurred
        
        // 🔄 Compare adjacent elements
        for(int j = 0; j <= i; j++) {
            if(arr[j] > arr[j + 1]) {
                swaps = true;  // ✅ Mark that a swap occurred
                swap(arr[j], arr[j + 1]);
            }
        }
        
        // 🎯 If no swaps occurred, array is sorted
        if(swaps == false) break;
    }
}
```
[Practice on GeeksForGeeks](https://www.geeksforgeeks.org/problems/bubble-sort/1)

> 💡 **Optimization**: The `swaps` flag helps break out early if array becomes sorted before all passes are complete.

## 📥 Insertion Sort
```cpp
void insertionSort(vector<int>& arr) {
    // 🔄 Start from second element
    for(int i = 1; i <= arr.size() - 1; i++) {
        // 🔍 Find correct position for arr[i] in sorted portion [0...i-1]
        for(int j = 0; j <= i - 1; j++) {
            if(arr[i] < arr[j]) {
                int dummy = arr[i];  // 📝 Store current element
                
                // ➡️ Right shift elements to make space
                for(int k = i - 1; k >= j; k--) {
                    arr[k + 1] = arr[k];
                }
                
                arr[j] = dummy;  // 📥 Insert element at correct position
                break;
            }
        }
    }
}
```
[Practice on GeeksForGeeks](https://www.geeksforgeeks.org/problems/insertion-sort/1)

## 📋 Upcoming Implementations
> 🔗 See [Issue #X: Implement Advanced Sorting Algorithms](https://github.com/kirankigi5/Strivers_A2Z_DSA_SHEET/issues/X)
- [ ] Merge Sort
- [ ] Quick Sort
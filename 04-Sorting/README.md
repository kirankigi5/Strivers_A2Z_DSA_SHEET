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

## 🔄 Merge Sort

```cpp
class Solution {
  public:
    // 🧩 Merge two sorted subarrays: arr[l..mid] and arr[mid+1..r]
    void merge(vector<int>& arr, int l, int mid, int r)
    {
        int ptr1 = l;         // 🔍 Pointer for the left subarray
        int ptr2 = mid + 1;   // 🔍 Pointer for the right subarray
        
        vector<int> dummy_array; // 🛠️ Temporary array to store merged result
        
        // 🔁 Merge the two subarrays in sorted order
        while(ptr1 <= mid && ptr2 <= r)
        {
            if(arr[ptr1] < arr[ptr2])  // ✅ Left element is smaller
            {
                dummy_array.push_back(arr[ptr1]);
                ptr1++;
            }
            else  // ✅ Right element is smaller or equal
            {
                dummy_array.push_back(arr[ptr2]);
                ptr2++;
            }
        }
        
        // 🔄 Copy any remaining elements from the left subarray
        while(ptr1 <= mid)
        {
            dummy_array.push_back(arr[ptr1]);
            ptr1++;
        }
        
        // 🔄 Copy any remaining elements from the right subarray
        while(ptr2 <= r)
        {
            dummy_array.push_back(arr[ptr2]);
            ptr2++;
        }
        
        // 📥 Copy the merged elements back to the original array
        for(int i = l; i <= r; i++)
        {
            arr[i] = dummy_array[i - l];
        }
    }
  
    // 🔄 Recursive merge sort function
    void mergeSort(vector<int>& arr, int l, int r) {
        // 🛑 Base case: if the array has 1 or no elements
        if(l == r) return;
        
        int mid = l + (r - l) / 2;  // 🧠 Calculate the middle index
        
        // 🔁 Sort the left half
        mergeSort(arr, l, mid);
        
        // 🔁 Sort the right half
        mergeSort(arr, mid + 1, r);
        
        // 🧩 Merge the two sorted halves
        merge(arr, l, mid, r);
    }
};
```

[Practice on GeeksForGeeks](https://www.geeksforgeeks.org/problems/merge-sort/1)


## ⚡ Quick Sort 
```cpp
class Solution {
public:
    // 🚀 Quick Sort: Recursively sorts the array using the partition function
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // 🔪 Get pivot index after placing pivot in the correct position
            int p_index = partition(arr, low, high);

            // 🔁 Recursively sort elements before and after partition
            quickSort(arr, low, p_index - 1);
            quickSort(arr, p_index + 1, high);
        }
    }

    // 📍 Partition Function: Uses the first element as pivot (Hoare's Partition Scheme)
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];      // 🎯 Choose first element as pivot
        int i = low + 1;           // 👉 Start from next element
        int j = high;              // 👈 Start from the end

        // 🔄 Continue until the two pointers cross
        while (i <= j) {
            // ➡️ Move `i` to the right as long as elements are ≤ pivot
            while (i <= high && arr[i] <= pivot) i++;

            // ⬅️ Move `j` to the left as long as elements are > pivot
            while (j >= low && arr[j] > pivot) j--;

            // 🔁 Swap elements out of place
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // 🔄 Put pivot in its correct sorted position
        swap(arr[low], arr[j]);

        // 📍 Return the pivot's final position
        return j;
    }
};
```
[Practice on GeeksForGeeks](https://www.geeksforgeeks.org/problems/quick-sort/1)

## 💻 Problems & Solutions

| Problem | Status | Solution |
|---------|---------|-----------|
| [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) | ✅ Solved | [View Solution](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/6740168/1752-check-if-array-is-sorted-and-rotate-upf0/) |
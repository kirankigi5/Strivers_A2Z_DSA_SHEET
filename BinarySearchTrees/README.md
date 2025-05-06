# Binary Search Trees
- Prerequisite: [Binary Trees](../BinaryTrees/Trees.md)
---
## Properties of BST
- The key property of a Binary Search Tree is:
- For any node in the tree:
    -   `
        (node->left)->val < node->val < (node->right)->val
        `
    - $L < N < R$

This means:
- All nodes in left subtree must be less than current node
- All nodes in right subtree must be greater than current node
- This property must be true for every node in the tree
- The entire left subtree should in itself be a BST
- The entire right subtree should in itself be a BST

- Are duplicates allowed in BST?
    - Ideally, for general implementation dupliactes are not allowed.
    - What if we want to have duplicates?
        - We loosen the condition to,
            - $L \leq N < R$
        - Or, at a single node we can store `(node->val, node->freq)` keeping the condition($L < N < R$) same.

- What is the upside of a BST?
    - The worst case time complexity of search in a BinaryTree is O(N).
    - In BST generally, the height of the tree is $\approx \log_2(N)$. Where, $N$ is the total no of nodes. Not a necessity but in almost all the cases it is true. Search in a BST takes $\approx O(\log_2(N)) \approx O(H)$. $H$ is the height of the tree.
---

## Problems

| No. | Problem | Status | Solution |
|-----|---------|--------|----------|
| 1 | [Ceil in BST](https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1) | $✅$ Solved | [Solution](https://discuss.geeksforgeeks.org/comment/0345f193-c119-4d22-8d35-252cd49f18f1/practice) |
| 2 | [Floor in BST](https://www.geeksforgeeks.org/problems/floor-in-bst/1) | $✅$ Solved | [Solution](https://discuss.geeksforgeeks.org/comment/75df8740-1522-40f9-89fc-5430f59453ea/practice) |
| 3 | [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/search-in-a-binary-search-tree/solutions/6673831/search-in-bst-using-c-easy-recursion-bea-apwq/) |
| 4 | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | $✅$ Solved | [Solution](https://leetcode.com/problems/insert-into-a-binary-search-tree/solutions/6673842/insert-into-a-binary-search-tree-bst-usi-r3ok/) |
| 5 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/) | $❌$ Unsolved | - |
| 6 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1612428730/) | $✅$ Solved | [Solution](https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/6670383/beats-100-c-easy-to-follow-bst-k-th-smallest-tutorial/) |
| 7 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) | $✅$ Solved | - |
| 8 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | $✅$ Solved | [Solution](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/6673587/c-easy-to-follow-brute-to-optimal-soluti-k1br/) |
| 9 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/) | $❌$ Unsolved | - |
| 10 | [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/description/) | $❌$ Unsolved | - |
| 11 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | $❌$ Unsolved | - |
| 12 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | $❌$ Unsolved | - |
| 13 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/) | $❌$ Unsolved | - |
| 14 | [Largest BST in Binary Tree](https://takeuforward.org/plus/dsa/problems/largest-bst-in-binary-tree) | $❌$ Unsolved | - |
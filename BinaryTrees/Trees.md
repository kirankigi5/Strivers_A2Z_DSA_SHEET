# Introduction to Binary Trees

## Basic Tree Terminology

- **Node**: A fundamental unit of a tree data structure that contains data and references/pointers to other nodes (children)

- **Root**: The topmost node of a tree from which all other nodes descend. It has no parent node.

- **Parent**: A node that has one or more child nodes connected directly below it

- **Children**: Direct descendants of a node. For any node X, if there is an edge from X to Y, then Y is a child of X. In a binary tree, each node can have at most 2 children (left child and right child).

- **Ancestor**: Any node that lies on the path from the root to a particular node. Every node (except the root) has at least one ancestor.

- **Leaf**: A node that has no children (also called terminal nodes or external nodes)

---
## Binary Tree Types

- **Full Binary Tree:** Every node in a Full Binary Tree either has 0 or 2 children.

- **Complete Binary Tree:** All levels are completely filled except the last level. The last level has all nodes on left as possile.

- **Perfect Binary Tree:** All leaf nodes are at the same level.

- **Balanced Binary Tree:** Height of the tree at max of $\log(N)$. Where, $N$ is the number of nodes.

- **Degenerate Tree:** $\boxed{\text{height of tree} = N}$ . Skew tree, a linked list.

---
## Binary Tree representation in c++
```cpp
struct Node {
    int data;           // data stored in the node
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child

    // Constructor
    Node (int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
```

### Construct root node
```cpp
int main(void)
{
    // Create root node with value 1
    // new allocates memory on heap and returns pointer
    // Node(1) calls the constructor with value 1

    struct Node* root = new Node(1); 

    // Create left child with vaue 2
    // Attach it to root's left pointer
    root->left        = new Node(2);

    // Create right child with value 3
    // Attach it to root's right pointer
    root->right       = new Node(3); 

    return 0;
}
```
---
## Tree Traversal

### Depth First Search (DFS)

| Traversal Type | Order | LeetCode |
|---------------|-------|----------|
| Inorder | Left → Root → Right | [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) |
| Preorder | Root → Left → Right | [144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) |
| Postorder | Left → Right → Root | [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) |

### Breadth First Search (BFS)
Also known as ***Level Order Traversal***, BFS visits all nodes at the current level before moving to nodes at the next level.
[102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

## Problems

| No. | Problem | Status | Solution |
|-----|---------|--------|----------|
| 1 | [Preorder Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/6673878/c-recursive-easy-to-follow-beats-by-kigi-2x80/) |
| 2 | [Inorder Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/6673889/c-recursive-inorder-traversal-easy-to-fo-y5qc/) |
| 3 | [Post-order Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/6673892/c-recursive-postorder-traversal-easy-to-cyziz/) |
| 4 | [Level order Traversal / Level order traversal in spiral form](https://leetcode.com/problems/binary-tree-level-order-traversal/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/6406262/c-easy-beats100-dfs-approach-with-explai-ooro/) |
| 5 | [Iterative Preorder Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/6674118/c-iterative-preorder-traversal-dfs-using-stack-super-clean-beats/) |
| 6 | [Iterative Inorder Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | $❌$ Unsolved | - |
| 7 | [Post-order Traversal of Binary Tree using 2 stack](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | $❌$ Unsolved | - |
| 8 | [Post-order Traversal of Binary Tree using 1 stack](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | $❌$ Unsolved | - |
| 9 | [Preorder, Inorder, and Postorder Traversal in one Traversal](https://takeuforward.org/plus/dsa/problems/pre,-post,-inorder-in-one-traversal) | $❌$ Unsolved | - |
| 10 | [Height of a Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | $✅$ Solved | [Solution](https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/6674164/c-recursive-maximum-depth-of-binary-tree-p0s7/) |
| 11 | [Check if the Binary tree is height-balanced or not](https://leetcode.com/problems/balanced-binary-tree/description/) | $❌$ Unsolved | - |
| 12 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/) | $❌$ Unsolved | - |
| 13 | [Maximum path sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) | $❌$ Unsolved | - |
| 14 | [Check if two trees are identical or not](https://leetcode.com/problems/same-tree/description/) | $❌$ Unsolved | - |
| 15 | [Zig Zag Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) | $❌$ Unsolved | - |
| 16 | [Boundary Traversal of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/description/) | $❌$ Unsolved | - |
| 17 | [Vertical Order Traversal of Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/) | $❌$ Unsolved | - |
| 18 | [Top View of Binary Tree](https://takeuforward.org/plus/dsa/problems/top-view-of-bt?tab=editorial) | $❌$ Unsolved | - |
| 19 | [Bottom View of Binary Tree](https://takeuforward.org/plus/dsa/problems/bottom-view-of-bt?tab=editorial) | $❌$ Unsolved | - |
| 20 | [Right/Left View of Binary Tree](https://leetcode.com/problems/binary-tree-right-side-view/description/) | $❌$ Unsolved | - |
| 21 | [Symmetric Binary Tree](https://leetcode.com/problems/symmetric-tree/description/) | $❌$ Unsolved | - |
| 22 | [Print Root to Node Path in Binary Tree](https://takeuforward.org/plus/dsa/problems/print-root-to-note-path-in-bt) | $❌$ Unsolved | - |
| 23 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | $❌$ Unsolved | - |
| 24 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | $❌$ Unsolved | - |
| 25 | [Check for Children Sum Property in Binary Tree](https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/) | $❌$ Unsolved | - |
| 26 | [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/) | $❌$ Unsolved | - |
| 27 | [Minimum Time to Burn Binary Tree](https://takeuforward.org/plus/dsa/problems/minimum-time-taken-to-burn-the-bt-from-a-given-node?tab=editorial) | $❌$ Unsolved | - |
| 28 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/) | $❌$ Unsolved | - |
| 29 | [Requirements to Construct Unique Binary Tree](https://takeuforward.org/plus/dsa/problems/requirements-needed-to-construct-a-unique-bt?tab=editorial) | $❌$ Unsolved | - |
| 30 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | $❌$ Unsolved | - |
| 31 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | $❌$ Unsolved | - |
| 32 | [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | $❌$ Unsolved | - |
| 33 | [Morris Inorder Traversal of Binary Tree](https://leetcode.com/problems/binary-tree-inorder-traversal/) | $❌$ Unsolved | - |
| 34 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | $❌$ Unsolved | - |

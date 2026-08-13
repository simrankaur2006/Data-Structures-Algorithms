A Binary Search Tree (BST) adds one simple rule at every node:

Left subtree < Node < Right subtree

That's it. Because of this rule:

All smaller values go left.
All bigger values go right.
This is true for every node, not just the root.
Example BST:

        50
       /  \
     30     70
    /  \    /  \
  20   40  60   80

Everything left of 50 is < 50, everything right is > 50 — and the same rule applies inside each smaller subtree too (e.g., 20 < 30 < 40).

Downside to remember: if you insert sorted data (1,2,3,4,5...) one by one, the BST becomes a straight line (skewed tree) and height becomes O(n) — search becomes as slow as a normal list. That's why balanced BSTs (AVL, Red-Black) exist.


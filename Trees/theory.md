A Tree is a non-linear data structure made of nodes connected by edges, arranged in a hierarchical (parent-child) structure — like a family tree or a folder/file system.

Key Terms:

Root — the topmost node (no parent)
Parent/Child — a node directly connected above/below another
Leaf — a node with no children
Edge — connection between two nodes
Height — longest path from a node down to a leaf
Depth/Level — distance of a node from the root

Why use Trees instead of Linked Lists?
Linked Lists are linear (one path). Trees let each node branch into multiple children, which is perfect for representing hierarchical relationships (like a company org chart) and enables much faster searching (like Binary Search Trees).

Basic Node Structure (Binary Tree)
cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
2. Types of Trees
Theory (Easy Words)
Binary Tree — each node has at most 2 children (left and right).
Full Binary Tree — every node has either 0 or 2 children (never just 1).
Complete Binary Tree — all levels are completely filled, except possibly the last level, which is filled left to right.
Perfect Binary Tree — all internal nodes have 2 children AND all leaves are at the same level.
Balanced Binary Tree — height difference between left and right subtree of any node is at most 1 (keeps operations fast, O(log n)).
Binary Search Tree (BST) — a binary tree where left subtree values < node < right subtree values (enables fast searching).
Skewed Tree — every node has only one child (basically becomes like a linked list) — worst case for performance.

Visual comparison:

Full Binary Tree:        Complete Binary Tree:      Skewed Tree:
      1                        1                          1
     / \                      / \                          \
    2   3                    2   3                          2
   / \                      /                                 \
  4   5                    4                                   3
3. Binary Tree Creation
Theory (Easy Words)

You build a tree by creating nodes and manually linking left/right pointers, OR you build it from an array/input using level order insertion (like filling a Complete Binary Tree).

Manual Creation
cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = nullptr; right = nullptr; }
};

int main() {
    // Build this tree manually:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Tree created with root: " << root->data << endl;
    return 0;
}
Creation via Level Order Input (Interactive)
cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = nullptr; right = nullptr; }
};

Node* buildTree() {
    int val;
    cout << "Enter root value (-1 for no node): ";
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Enter left child of " << curr->data << " (-1 if none): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 if none): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

Idea: Use a queue to process nodes level by level, asking for each node's children — this naturally builds the tree in level order (this is the same pattern used later in Level Order Traversal).

4. Tree Traversals — Preorder, Inorder, Postorder
Theory (Easy Words)

Traversal = visiting every node exactly once, in some defined order. There are 3 classic Depth First traversals — they differ only in when you visit (print) the root, relative to its children.

Traversal	Order	Easy way to remember
Preorder	Root → Left → Right	Root comes first
Inorder	Left → Root → Right	Root comes in the middle
Postorder	Left → Right → Root	Root comes last

All three use the same recursive pattern — just the position of the cout line changes.

Preorder and Inorder
cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = nullptr; right = nullptr; }
};

void preorder(Node* root) {
    if (root == nullptr) return;   // base case

    cout << root->data << " ";   // 1. visit Root first
    preorder(root->left);         // 2. then Left
    preorder(root->right);        // 3. then Right
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);          // 1. Left first
    cout << root->data << " ";   // 2. then Root
    inorder(root->right);         // 3. then Right
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);   // Output: 1 2 4 5 3
    cout << "\nInorder: ";
    inorder(root);    // Output: 4 2 5 1 3
    return 0;
}
5. Postorder
Theory (Easy Words)

Visit children first, root last. Very useful for problems like deleting a tree (must delete children before the parent) or evaluating expression trees.

cpp
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);        // 1. Left first
    postorder(root->right);       // 2. then Right
    cout << root->data << " ";   // 3. Root last
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Postorder: ";
    postorder(root);   // Output: 4 5 2 3 1
    return 0;
}

Memory Trick:

PRE-order  = Pre (before children) -> Root Left Right
IN-order   = In (in-between children) -> Left Root Right
POST-order = Post (after children) -> Left Right Root
6. Max Depth / Height of a Binary Tree
Theory (Easy Words)

Height = number of edges (or nodes, depending on convention) on the longest path from root to a leaf.

Recursive Idea: Height of a tree = 1 + max(height of left subtree, height of right subtree). This is the classic recursive "trust the smaller subproblem" pattern.

cpp
int maxDepth(Node* root) {
    if (root == nullptr) return 0;   // base case: empty tree has height 0

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height: " << maxDepth(root);  // Output: 3
    return 0;
}
7. Print Nodes at a Distance of K
Theory (Easy Words)

Given a root and a value k, print all nodes that are exactly k edges away from the root.

Idea: Recursively go down. Each time you go one level deeper, decrease k by 1. When k == 0, you've found a node at the correct distance — print it.

cpp
void printAtDistanceK(Node* root, int k) {
    if (root == nullptr) return;    // base case: no node here

    if (k == 0) {                   // reached the correct distance
        cout << root->data << " ";
        return;
    }

    printAtDistanceK(root->left, k - 1);    // go left, one level closer
    printAtDistanceK(root->right, k - 1);   // go right, one level closer
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Nodes at distance 2: ";
    printAtDistanceK(root, 2);   // Output: 4 5
    return 0;
}

Note: This finds nodes at distance k from the root only. A trickier variant ("nodes at distance k from a given target node," which could be above the target too) needs extra logic to track ancestors — that's a more advanced follow-up problem.

8. Level Order Traversal
Theory (Easy Words)

Visit nodes level by level, left to right — this is a Breadth First Search (BFS), unlike Preorder/Inorder/Postorder which are Depth First.

Idea: Use a Queue. Push the root. Then repeatedly: pop a node, print it, push its children. This naturally processes nodes level by level because of the Queue's FIFO nature.

cpp
#include <iostream>
#include <queue>
using namespace std;

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order: ";
    levelOrder(root);   // Output: 1 2 3 4 5
    return 0;
}
Level Order — Printing Level by Level (on separate lines)
cpp
void levelOrderByLevel(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // number of nodes at THIS level

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        cout << "\n";   // move to next line after finishing a level
    }
}

Key Trick: Capture q.size() before the inner loop starts — this tells you exactly how many nodes belong to the current level, so you know when to print a newline.

9. Size of a Binary Tree
Theory (Easy Words)

Size = total number of nodes in the tree.

Recursive Idea: Size of tree = 1 (for current node) + size of left subtree + size of right subtree.

cpp
int treeSize(Node* root) {
    if (root == nullptr) return 0;   // base case: empty tree has 0 nodes

    return 1 + treeSize(root->left) + treeSize(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Size: " << treeSize(root);  // Output: 5
    return 0;
}
Iterative Version (using Level Order / Queue)
cpp
int treeSizeIterative(Node* root) {
    if (root == nullptr) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        count++;

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
    return count;
}
10. Max Element in Binary Tree
Theory (Easy Words)

Find the largest value present anywhere in the tree (note: this is a plain Binary Tree, NOT a BST — so we can't use any ordering shortcut, we must check every node).

Recursive Idea: Max of tree = max(root's data, max of left subtree, max of right subtree).

cpp
int maxElement(Node* root) {
    if (root == nullptr) return INT_MIN;   // base case: no contribution from empty subtree

    int leftMax = maxElement(root->left);
    int rightMax = maxElement(root->right);

    return max({root->data, leftMax, rightMax});
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Max Element: " << maxElement(root);  // Output: 9
    return 0;
}
Iterative Version (using Level Order / Queue)
cpp
#include <climits>

int maxElementIterative(Node* root) {
    if (root == nullptr) return INT_MIN;

    queue<Node*> q;
    q.push(root);
    int maxVal = INT_MIN;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        maxVal = max(maxVal, curr->data);

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
    return maxVal;
}
Quick Summary Table
Operation	Technique	Time Complexity
Preorder/Inorder/Postorder	Recursion (DFS)	O(n)
Level Order Traversal	Queue (BFS)	O(n)
Max Depth / Height	Recursion	O(n)
Nodes at Distance K	Recursion	O(n)
Size of Tree	Recursion or Queue	O(n)
Max Element	Recursion or Queue	O(n)

All traversal-based operations on a tree with n nodes are O(n) — you must visit every node at least once, since there's no shortcut without extra structure (like a BST's ordering).

Key Pattern to Remember

Almost every Tree problem in this list follows the same recursive skeleton:

cpp
returnType solve(Node* root) {
    if (root == nullptr) return baseCaseValue;   // handle empty tree

    // combine results from left and right subtrees
    returnType leftResult = solve(root->left);
    returnType rightResult = solve(root->right);

    return combine(root->data, leftResult, rightResult);
}

Once this pattern clicks, height, size, max element, sum of nodes, counting leaves, etc. all become variations of the same template — just change what "combine" means.

DFS (recursion) vs BFS (queue):

Use recursion when the problem is naturally about subtrees (height, size, sum, max).
Use a queue when the problem is about levels/layers (level order, nodes at distance k from root in level-order style, shortest path in level terms).
Tips to Practice
Draw the tree on paper first, then manually write out Preorder/Inorder/Postorder sequences before checking with code — this cements the Root-position trick.
For every new "compute something about the tree" problem, first ask: "What do I need from the left subtree? What do I need from the right subtree? How do I combine them with the root?" — this mental model solves 90% of basic tree problems.
Practice converting a recursive traversal into an iterative version using an explicit stack (for Preorder/Inorder/Postorder) — a common interview follow-up question.
Try modifying printAtDistanceK to work from any given node, not just the root — this bridges into more advanced tree problems.



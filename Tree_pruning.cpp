Given a binary tree root, prune the tree so that subtrees containing all 0s are removed.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

1

0

1

0

0

0
Output
Visualize

0

1

0

1
Explanation

We do not remove the tree at the root or its right child because they still have a 1 as a descendant.
  //https://binarysearch.com/problems/Tree-Pruning
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool prune(Tree* root) {
    if (root == NULL) return 0;

    bool a = prune(root->left);
    bool b = prune(root->right);
    if (a == 0) {
        root->left = NULL;
    }
    if (b == 0) {
        root->right = NULL;
    }
    if (root->val == 0 && !(a || b)) {
        return 0;
    }
    if (root->val == 1) {
        return 1;
    }
    return 1;
}

Tree* solve(Tree* root) {
    bool x = prune(root);

    return x == 0 ? NULL : root;
}

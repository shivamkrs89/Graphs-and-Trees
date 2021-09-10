A univalue tree is a tree where all nodes under it have the same value.

Given a binary tree root, return the number of univalue subtrees.

Constraints

    1 ≤ n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

1

0

1

0

1

1
Output

5

Explanation

The unival trees include four leaf nodes (three of them are 1s, the other one is the rightmost 0), and one subtree in the middle (containing all 1s).
Example 2
Input
Visualize

root =

1

0

0
Output

2

Explanation

The two leaf nodes are unival trees.

  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool countsub(Tree* root, int& count) {
    if (root == NULL) return 1;

    if (root->left == NULL && root->right == NULL) {
        count++;
        return 1;
    }

    bool v1 = countsub(root->left, count);
    bool v2 = countsub(root->right, count);

    if (root->left != NULL && root->val != root->left->val) return 0;
    if (root->right != NULL && root->val != root->right->val) return 0;

    if (v1 && v2) {
        count++;
        return 1;
    }
    return 0;
}
int solve(Tree* root) {
    int c = 0;
    bool b1 = countsub(root, c);
    return c;
}

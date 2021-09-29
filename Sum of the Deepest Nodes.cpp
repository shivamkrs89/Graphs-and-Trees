Given a binary tree root, find the sum of the deepest node values.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

0

5

9

1

3

4

2
Output

6

Explanation

Since values 4 and 2 are deepest.
Example 2
Input
Visualize

root =

0

5

9

3
Output

3
//https://binarysearch.com/problems/Sum-of-the-Deepest-Nodes

Time complexity O(N) N number of nodes as we do dfs

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(Tree* root, int h, int& mh, int& s) {
    if (root == NULL) return;
    if (h > mh) {
        s = 0, mh = h;
    }
    if (root->left == NULL && root->right == NULL && h == mh) {
        s += root->val;
    }

    dfs(root->left, h + 1, mh, s);
    dfs(root->right, h + 1, mh, s);
}
int solve(Tree* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;

    int h = 0, mh = 0, s = 0;
    dfs(root, mh, h, s);
    return s;
}

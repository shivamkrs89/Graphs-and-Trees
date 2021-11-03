Given a binary tree root, repeatedly delete all leaves that have even values. That is, if after deletions, a node becomes a leaf with an even value, it too should be deleted.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

3

2

4

6

12

4

7
Output
Visualize

3

4

6

7
//https://binarysearch.com/room/Boolean-Pandits-JBSmrpcyCa?questionsetIndex=1

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {
    if(root==NULL)
    return root;
     if(root->left!=NULL)
    root->left=solve(root->left);
    if(root->right!=NULL)
    root->right=solve(root->right);
    
    if(root->left==NULL && root->right==NULL && (root->val)%2==0)
    {
       return NULL;
    }
    return root;
}

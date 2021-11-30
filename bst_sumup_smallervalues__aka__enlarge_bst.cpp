Given a binary search tree root, replace every node's value v by its value plus the sum of all other values in the tree that are greater than v.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
4

2

5

1

3

Output
Visualize
9

14

5

15

12
//link of problem
https://binarysearch.com/problems/Enlarge-BST

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solveutil(Tree* root,int &psum)
{
    if(root==NULL)
       return psum;

    int addvr=solveutil(root->right,psum);
    
    //int real_val=root->val;
    root->val+=(addvr);
    psum=root->val;//keeps track of all smaller values
    int addvl=solveutil(root->left,psum);
    
    

    return psum;

}


Tree* solve(Tree* root) {
    int psum=0;
    solveutil(root,psum);

    return root;
}
//[0, null, [2, [1, null, null], null]] //zig zag case

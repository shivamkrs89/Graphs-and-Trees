You are given two binary trees root, and target. Return whether target is a subtree of root — that is, whether there's a node in root that is identically same in values and structure as root including all of its descendants.
Example 1
Input
Visualize

root =

1

2

3

4

5

6

7

target =

3

4

5

6

7
Output

true

Example 2
Input
Visualize

root =

1

2

3

4

5

6

7

target =

3

5
Output

false

Example 3
Input
Visualize

root =

0

5

1

target =

0

5

1
Output

true
//problem link https://binarysearch.com/problems/Subtree

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 bool solveutil(Tree* root,Tree* target)
 {
     if(root==NULL ^ target==NULL)
     return 0;
     else if(root==NULL && target==NULL)
     return 1;
     bool bleft=0,bright=0;
     if(root->val==target->val)
     {
        bleft=solveutil(root->left,target->left);
        bright=solveutil(root->right,target->right);
     }
     else 
     return 0;

        return bleft && bright;
 }
bool solve(Tree* root, Tree* target) {
    if(root==NULL)
    return 0;

    if(root->val==target->val) //when find equal val node we search for subtree equality
    {
        bool b1=solveutil(root,target);
        if(b1==1)
        return b1;
    }
    bool bl=solve(root->left,target);
    bool br=solve(root->right,target);

    return bl||br;
}

Given a binary tree root, consider deleting an edge in the tree so that the tree becomes disjoint with two trees. Then, take the sum of each subtree and multiply the two numbers. Return the largest such product we can get after deleting one edge.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
1

2

3

4

5

Output
50
Explanation
If we delete the 3 - 5 edge, then we can have (1 + 2 + 3 + 4) * 5 = 50
  
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int solveutil(Tree* root,int treesum,int &maxi)
{
    if(root==NULL)
    return 0;

    int lv=solveutil(root->left,treesum,maxi);

    int rv=solveutil(root->right,treesum,maxi);

    int subtreesum=lv+rv+root->val;

    maxi=max(maxi,subtreesum*(treesum-subtreesum));

    return subtreesum;
}

 void getsum(Tree* root,int &sum)
 {
     if(root==NULL)
     return ;

     getsum(root->left,sum);

     sum+=(root->val);

     getsum(root->right,sum);
 }
int solve(Tree* root) {
    int sum=0;
    getsum(root,sum);
    int maxi=0;
    solveutil(root,sum,maxi);

    return maxi;
}

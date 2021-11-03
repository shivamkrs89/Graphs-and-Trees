Given a binary tree root, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself. You can assume there is one unique solution.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

5

2

-5
Output

2

Explanation

2 occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.

  
  //code
  /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solveutil(Tree* root,unordered_map<int,int> &m1,int &maxfr,int &num)
{
    if(root==NULL)
    return 0;

    int lv=solveutil(root->left,m1,maxfr,num);
    int rv=solveutil(root->right,m1,maxfr,num);

    int sum=lv+rv+root->val;
    
    m1[sum]+=1;

    if(m1[sum]>maxfr){
    maxfr=m1[sum];num=sum;
    }

    return sum;
     
}

int solve(Tree* root) {
 
    unordered_map<int,int> m1;
     int maxfr=0;
     int num;
    solveutil(root,m1,maxfr,num);
   
    return num;
}

Given a binary tree root, convert it to a singly linked list using an inorder traversal.

Constraints

    n ≤ 100,000 where n is the number of nodes in root

Example 1
Input
Visualize

root =

2

1

4

3
Output
Visualize

//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

void inorder(Tree* root,LLNode* &head)
{
if(root==NULL)
return;

inorder(root->left,head);

head->next=new LLNode(root->val);
head=head->next;

inorder(root->right,head);

} 
LLNode* solve(Tree* root) {
    LLNode* head=new LLNode(10);
    LLNode* rhead;
    rhead=head;
    inorder(root,head);
       rhead=rhead->next;
       return rhead;
}

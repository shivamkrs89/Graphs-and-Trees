Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
Explanation:


Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
Explanation: 

 

 

 Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
Explanation:


Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
Explanation: 
//code
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
Explanation:


Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
Explanation: 
// { Driver Code Starts







 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
//4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
//1 2 N 3 N 4 N
//4 10 N 5 5 N N 7 N 
//17 N 1 N 9 N 2 N 11 N 16 N 8 N 5 N 3 N 10 N 13 N 5 N 13 N 7 N 10 N 4 N 7 N 2 N 12 N 16
class Solution {
public:
   
   void rightview(Node* root,vector<int> &rv,int cur_level,int &req_level)
   {
       if(root==NULL)
       return ;
             if(root->right){
           rv.push_back(root->data);
       rightview(root->right,rv,cur_level+1,req_level);
}       else if(root->left){
    rv.push_back(root->data);
       rightview(root->left,rv,cur_level+1,req_level);
}
       
   }
   void leftview(Node* root,vector<int> &lv,int cur_level,int &req_level)
   {
       if(root==NULL)
       return ;
       if(root->left){
           lv.push_back(root->data);
       leftview(root->left,lv,cur_level+1,req_level);
}       else if(root->right){
    lv.push_back(root->data);
       leftview(root->right,lv,cur_level+1,req_level);
}       
   }
   void getleafs(Node *root,vector<int>& leafs)
   {
       if(root==NULL)
       return ;
       getleafs(root->left,leafs);
       if(root->left==NULL && root->right==NULL)
       {
       leafs.push_back(root->data);
       
       } 
       getleafs(root->right,leafs);
   }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> boundary;
        boundary.push_back(root->data);
        vector<int> lv;
        int level=1,req_level=1;
        leftview(root->left,lv,level,req_level);
    
          vector<int> leafs;
        getleafs(root,leafs);
        vector<int> rv;
         level=1,req_level=1;
        rightview(root->right,rv,level,req_level);
      
        int i;
        
        for(i=0;i<lv.size();i++)
        {
            boundary.push_back(lv[i]);
        }
        
        for(i=0;i<leafs.size();i++)
        {
         boundary.push_back(leafs[i]);
        }
        if(rv.size())
        reverse(rv.begin(),rv.end());
         for(i=0;i<int(rv.size());i++)
        {
            boundary.push_back(rv[i]);
        }
        
        return boundary;
    }
};



 

 

 

 

 

 

 

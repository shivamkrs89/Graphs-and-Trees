/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 

Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

//code goes here
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends

void R2Ltrav(stack<Node *> s1,vector<int> &v1);
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
//used stack to store them accordingly
void L2Rtrav(stack<Node *> s1,vector<int> &v1)
{
    if(s1.empty())
    return ;
    stack<Node *> s2;
    while(!s1.empty())
    {
        Node *n1=s1.top();
        v1.push_back(n1->data);
         if(n1->right!=NULL)
        s2.push(n1->right);
        if(n1->left!=NULL)
        s2.push(n1->left);
        
        s1.pop();
        
    }
    if(s2.empty())
    return ;
    R2Ltrav(s2,v1);
}

void R2Ltrav(stack<Node *> s1,vector<int> &v1)
{
    stack<Node *> s2;
    while(!s1.empty())
    {
        Node *n1=s1.top();
        v1.push_back(n1->data);
        if(n1->left!=NULL)
        s2.push(n1->left);
        if(n1->right!=NULL)
        s2.push(n1->right);
        s1.pop();
        
    }
    
    L2Rtrav(s2,v1);
}

vector<int> findSpiral(Node *root)
{
    //Your code here
    stack<Node *> s1;
    vector<int> v1;
    if(root==NULL)//if no nodes
    return v1;
    s1.push(root);
    
    L2Rtrav(s1,v1);
    
    return v1;
}


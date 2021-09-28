Given a binary tree root, shift all the nodes as far right as possible while maintaining the relative ordering in each level.
//https://binarysearch.com/problems/Tree-Shifting
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

6

7
Output
Visualize

1

2

3

4

5

6

7
Example 2
Input
Visualize

root =

1

2

3

4

5
Output
Visualize

1

2

3

4

5
Example 3
Input
Visualize

root =

1

2

3

4

5
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

Tree* solve(Tree* root) {
    // If tree is empty
    if (!root) return NULL;

    stack<Tree*> st;
    queue<Tree*> q;

    // If right child exists
    if (root->right)
     q.push(root->right);
    
    root->right = NULL;

    // If left child exists
    if (root->left)
     q.push(root->left);
    
    root->left = NULL;

    // Push current node into stack
    st.push(root);

    while (!q.empty()) {
        int n = q.size();
        stack<Tree*> temp;

        // Iterate existing nodes
        // in the current level
        while (n--) {
            // If no right child exists
            if (!st.top()->right)
                // Set the rightmost
                // vacant node
                st.top()->right = q.front();

            // If no left child exists
            else {
                // Set rightmost vacant node
                st.top()->left = q.front();

                // Remove the node as both
                // child nodes are occupied
                st.pop();
            }

            // If r̥ight child exist
            if (q.front()->right)  // Push into the queue
                q.push(q.front()->right);

            // Vacate right child
            q.front()->right = NULL;

            // If left child exists
            if (q.front()->left)  // Push into the queue
                q.push(q.front()->left);

                                     // Vacate left child
            q.front()->left = NULL;

            // Add the node to stack to
            // maintain sequence of nodes
            // present in the level
            temp.push(q.front());
            q.pop();
                  }

        while (!st.empty()) 
          st.pop();
        // Add nodes of the next
        // level into the stack st
        
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();                      }
            }
    // Return the root of the
    // modified Tree
    return root;
}

  vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node *> s1;
     
        vector<int> v1;
          Node *curr=root;
        while(curr!=NULL || !s1.empty())
        {
          
            while(curr!=NULL)
            {
                s1.push(curr);
                curr=curr->left;
                //pushing left subtree node
            }
            
            
                v1.push_back(s1.top()->data);//pushing topof stack element in inorder
                curr=s1.top()->right;//curr is now right of top stack element
                s1.pop();//pop out that elementa s it's work is over
            
        }
    
        return v1;
    }

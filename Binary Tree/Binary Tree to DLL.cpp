class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node *prev = NULL, *head = NULL;  
    void solve(Node* root){
        if(root == NULL) return;
        
        solve(root->left);
        
        if(prev == NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        solve(root->right);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        solve(root);
        return head;
    }
};
```
/*
https://practice.geeksforgeeks.org/problems/mirror-tree/1
*/

void mirror(Node* root) 
{
    if(root==nullptr){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
}
```

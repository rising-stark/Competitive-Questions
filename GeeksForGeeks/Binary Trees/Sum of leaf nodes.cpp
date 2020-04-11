```
/*
https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes/1/
*/

int sumLeaf(Node* root)
{
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr){
        return root->data;
    }
    return sumLeaf(root->left)+sumLeaf(root->right);
}
```

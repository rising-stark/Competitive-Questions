```
/*
https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1/
*/

int countLeaves(Node* root)
{
  if(root==nullptr){
      return 0;
  }
  if(root->left==nullptr && root->right==nullptr){
      return 1;
  }
  return countLeaves(root->right)+countLeaves(root->left);
}

```

```
/*
https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1/
NOTE:
Now, this problem has some serious issues.
But they can all be handled using these precautions.
1. Print the output in sorted order (ascending).
2. Print only unique values.
3. Don't print endl (for c++) after printing the output.
*/

void printLeafs(Node *root, vector<int>& v){
    if(root==nullptr){
       return;
   }
   if(root->left==nullptr && root->right!=nullptr){
       v.push_back(root->right->data);
   }
   if(root->left!=nullptr && root->right==nullptr){
       v.push_back(root->left->data);
   }
   printLeafs(root->left ,v);
   printLeafs(root->right, v);
}

void printSibling(Node* root)
{
   vector<int> v;
   printLeafs(root, v);
   if(v.size()==0){
       cout<<-1;
   }
   else{
       sort(v.begin(), v.end());
       v.resize(unique(v.begin(), v.end()) - v.begin());
       for(int i=0;i< v.size();i++){
           cout<<v[i]<<" ";
       }
   }
}
```

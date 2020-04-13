```
/*
https://www.geeksforgeeks.org/sum-of-all-nodes-at-kth-level-in-a-binary-tree/?ref=leftbar-rightbar

Given a binary tree with N nodes and an integer K, the task is to find the sum of all the nodes present at the Kth level.

This can be done without using a queue which takes O(n) space.
The following code can provide the answer in O(1) space but just tracking which level we are currently on.
If the current level is == k, then return with the root->data because there is no need to go down further.

This code executes in O(n) time and O(1) space.
*/


int sumOfNodesAtNthLevel(struct node* root, int i, int k) {
	if(root==nullptr){
		return 0;
	}
	if(i==k){
		return root->data;
	}
	int a=sumOfNodesAtNthLevel(root->right, i+1, k);
	int b=sumOfNodesAtNthLevel(root->left, i+1, k));

	return (a+b);

}

```

https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

Diagonal Sum In Binary Tree
Difficulty: Easy

Consider Red lines of slope -1 passing between nodes (in following diagram).
The diagonal sum in a binary tree is the sum of all node’s data lying between these lines.
Given a Binary Tree of size N, print all diagonal sums.

For the following input tree, output should be 9, 19, 42.
9 is sum of 1, 3 and 5.
19 is sum of 2, 6, 4 and 7.
42 is sum of 9, 10, 11 and 12.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Print space separated integers which are the diagonal sums for every diagonal present in the tree with slope -1.

Your Task:
You don't need to take input.
Just complete the function diagonalSum() that takes root node of the tree as parameter and prints space seperated integers which
are the diagonal sums for every diagonal present in the tree with slope -1.
 
Constraints:
1<=T<=30
1<=N<=105

Example:
Input:
2
4 1 3 N N 3
10 8 2 3 5 2

Output:
7 4 
12 15 3

void sum(Node* root, int c, map<int, int> &mp){
    if(root==nullptr){
        return;
    }
    if(mp.find(c)!=mp.end()){
        int x=mp[c];
        x+=root->data;
        mp[c]=x;
    }else{
        mp.insert({c, root->data});
    }
    sum(root->left, c+1, mp);
    sum(root->right, c, mp);
}

void diagonalSum(Node* root) {
    map<int, int> mp;
    sum(root, 0, mp);
    map<int, int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<(it->second)<<" ";
    }
}

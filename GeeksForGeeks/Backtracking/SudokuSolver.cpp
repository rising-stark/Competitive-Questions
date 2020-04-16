https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0

Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku. For simplicity you may assume that there will be only one unique solution.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.

Output:
For each test case, in a new line, print the space separated values of the solution of the the sudoku.

Constraints:
1 <= T <= 10
0 <= mat[] <= 9

Example:
Input:
1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9

Explanation:
Testcase 1: The solved sudoku is:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

```
#include <iostream>
#include <cstring>
#define MAX 9
using namespace std;
bool isValid(int k, int x, int arr[][MAX]){
    int i,j;
    for(i=0;i<9;i++){
        if(arr[x/9][i]==k || arr[i][x%9]==k){
            return false;
        }
    }
    int m,n;
    for(m=2,i=(x/27)*3;m>=0;m--){
        for(j=(x%9- x%3), n=2;n>=0;n--){
            if(arr[i+m][j+n]==k){
                return false;
            }
        }
    }
    return true;
}
void printM(int arr[][MAX]){
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<arr[i][j]<<" ";
            //cout<<endl;
        }cout<<endl;
}
int getSudoku(int arr[][MAX], int i){
    //cout<<i<<" \n";
    //printM(arr);
    if(i==81){
        printM(arr);
        return 1;
    }
    if(arr[i/9][i%9]!=0){
        if(getSudoku(arr, i+1)==1){
            return 1;
        }
    }else{
        int k;
        for(k=1;k<=9;k++){
            if(isValid(k, i, arr)){
                arr[i/9][i%9]=k;
                if(getSudoku(arr, i+1)==1){
                    return 1;
                }else{
                    arr[i/9][i%9]=0;
                }
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,j,n=9;
        int arr[n][MAX];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cin>>arr[i][j];
        }
        getSudoku(arr, 0);
    }
}
```

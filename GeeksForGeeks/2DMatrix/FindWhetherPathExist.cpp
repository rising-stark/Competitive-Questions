https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0

Find whether path exist
Difficulty: Medium
                
Problems
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.

Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.


#include <iostream>
#define MAX 20
using namespace std;

int find(int arr[][MAX], int x, int y, int n){
    if(x<0 || y<0 || x>=n || y>=n || arr[x][y]<=0){
        return 0;
    }
    if(arr[x][y]==2){
        return 1;
    }
    arr[x][y]=-1;
    if(find(arr, x+1, y, n)==1){
        return 1;
    }
    if(find(arr, x-1, y, n)==1){
        return 1;
    }
    if(find(arr, x, y+1, n)==1){
        return 1;
    }
    if(find(arr, x, y-1, n)==1){
        return 1;
    }
    return 0;
    //arr[i][j]
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][MAX];
        int i,j,x=-1,y=-1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                int a;
                cin>>a;
                if(a==1){
                    x=i;y=j;
                }
                arr[i][j]=a;
            }
        }
        cout<<find(arr, x, y, n)<<endl;
    }
    return 0;
}

https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0

First and last occurrences of X
Difficulty: Basic
        
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x
in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x.
The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6

#include <iostream>
using namespace std;

int first(int arr[], int l, int h, int x){
    int f=-1;
    while(l<=h){
        int m=(h+l)/2;
        if(arr[m]==x){
            if(m==l || arr[m-1]!=x){
                return m;
            }else{
                f=m-1;
                h=m-1;
            }
        }
        else if(arr[m]>x){
            h=m-1;
        }else{
           l=m+1;
        }
    }
    return f;
}
int last(int arr[], int l, int h, int x){
    int f=-1;
    while(l<=h){
        int m=(h+l)/2;
        if(arr[m]==x){
            if(m==h || arr[m+1]!=x){
                return m;
            }else{
                f=m+1;
                l=m+1;
            }
        }
        else if(arr[m]>x){
            h=m-1;
        }else{
           l=m+1;
        }
    }
    return f;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,n, x;
        cin>>n>>x;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        int f,l;
        f=first(arr, 0, n-1, x);
        if(f==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<f<<" "<<last(arr, f, n-1, x)<<endl;
    }
}

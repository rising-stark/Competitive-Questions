/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int i,j,m,n;
        m=arr.size();
        n=arr[0].size();
        for(i=1;i<m;i++){
            arr[i][0]+=arr[i-1][0];
        }
        for(i=1;i<n;i++){
            arr[0][i]+=arr[0][i-1];
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                arr[i][j]+=min(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[m-1][n-1];
    }
};

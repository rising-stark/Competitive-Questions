/*https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3298/

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

// This approach is O(n*n) and O(n) space.

class Solution {
public:
    int findMaxLength(vector<int> arr) {
        int l,i,j,n;
        n=(int)arr.size();
        int dp[2][n+1];
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1]+(arr[i-1]==0);
            dp[1][i]=dp[1][i-1]+(arr[i-1]==1);
        }
        
        int res=0;
        for(l=1;l<n;l+=2){
            for(i=1;i<= (n-l);i++){
                j=i+l;
                int a=dp[0][j]-dp[0][i-1];
                int b=dp[1][j]-dp[1][i-1];
                if(a==b){
                    res=max(res, l+1);
                }
            }
        }
        return res;
    }
};


// This can be improved by O(n) time and space.

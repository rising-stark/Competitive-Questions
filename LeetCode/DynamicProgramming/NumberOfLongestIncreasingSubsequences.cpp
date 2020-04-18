https://leetcode.com/problems/number-of-longest-increasing-subsequence/

673. Number of Longest Increasing Subsequence
Medium
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

```
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int i,j,n,c=0;
        n=(int)arr.size();
        if(n<=1){
            return n;
        }
        int dp[n];
        int freq[n];
        memset(freq, 0, sizeof(freq));
        freq[0]=1;
        for(i=0;i<n;i++){
            dp[i]=1;
            freq[i]=1;
            for(j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(dp[i]==(dp[j]+1)){
                        freq[i]+=freq[j];
                    }else if(dp[i]<(dp[j]+1)){
                        dp[i]=dp[j]+1;
                        freq[i]=freq[j];
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }cout<<endl;
        for(i=0;i<n;i++){
            cout<<freq[i]<<" ";
        }cout<<endl;
        int ma=*max_element(dp, dp + n);
        cout<<ma<<endl;
        for(i=0;i<n;i++){
            if(dp[i]==ma){
                c+=freq[i];
            }
        }
        return c;
    }
};
```

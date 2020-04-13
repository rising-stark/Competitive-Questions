https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3285/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

```
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=(int)arr.size();
        int i, ma, sum;
        ma=arr[0];
        sum=0;
        for(i=0;i<n;i++){
            sum=max(arr[i], sum+arr[i]);
            ma=max(ma,sum);
        }
        return ma;
    }
};
```

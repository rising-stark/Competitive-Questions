https://leetcode.com/problems/non-overlapping-intervals/

435. Non-overlapping Intervals
Medium
Given a collection of intervals, find the minimum number of intervals needed to remove to make the rest of the intervals non-overlapping. 

Example 1:
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Example 2:
Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Example 3:
Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

bool fun(const vector<int> & a, const vector<int> &b){
        return a[0]<b[0];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int i,n;
        n=arr.size();
        if(n<2){
            return 0;
        }
        sort(arr.begin(), arr.end(), fun);
        vector<int> cur=arr[0];
        int c=0;
        for(i=1;i<n;i++){
            if(arr[i][0]<cur[1]){
                c++;
                if(cur[1]>arr[i][1]){
                    cur=arr[i];
                }
            }else{
                cur=arr[i];
            }
        }
        return c;
    }
};

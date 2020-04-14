https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

```

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i,n,c=0,j=0;
        n=(int)arr.size();
        for(i=0;i<n;i++){
            if(arr[i]==0){
                c++;
            }else{
                if(i>j)
                    arr[j]=arr[i];
                j++;
            }
        }
        for(i=j;i<n;i++){
            arr[i]=0;
        }
    }
};

```

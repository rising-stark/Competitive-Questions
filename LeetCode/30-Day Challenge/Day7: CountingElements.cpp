https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

Example 1:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Example 2:
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.

Example 3:
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

Example 4:
Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
 
Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000

```
// This is O(nLogn) solution using sorting and keeping track of elements till they are same and then adiing them all if x+1 appears.
class Solution {
public:
    int countElements(vector<int>& arr) {
        int i,n;
        n=(int)arr.size();
        sort(arr.begin(), arr.end());
        int c=0,d=1;
        for(i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                d++;
            }
            else{
                if((arr[i]-1) == arr[i-1]){
                c+=d;
            }
            d=1;
            }
        }
        return c;
    }
};


// Another solution using Hashing which is achieved in O(n) time but extra O(n) space.

class Solution {
public:
    int countElements(vector<int>& arr) {
        int i,n,c=0;
        n=(int)arr.size();
        unordered_set<int> s;
        for(int x:arr){
            s.insert(x);
        }
        for(int x:arr){
            if(s.find(x+1)!=s.end()){
                c++;
            }
        }
        return c;
    }
};

```

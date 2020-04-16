https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

Difficulty: Easy
An string of words is given, the task is to reverse the string using stack.

Input Format:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string s of words without spaces.

Output Format:
For each test case ,print the reverse of the string in new line. 

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function.

Constraints:
1 <= T <= 100
1 <= length of the string <= 100

Example:
Input:
2
GeeksQuiz
GeeksforGeeks
Output:
ziuQskeeG
skeeGrofskeeG

```
void reverse(char *str, int n)
{
    if(n==0){
        return;
    }
    stack<char> s;
    int i;
    for(i=0;i<n;i++){
        s.push(str[i]);
    }
    i=0;
    while(!s.empty()){
        str[i++]=s.top();
        s.pop();
    }
}
```

import os
import sys

sys.stdin = open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r")
sys.stdout = open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w")
n = int(input())
sum = 0
while(n>0):
	x = int(input())
	sum+=x
	n-=1
ans = str(sum)
for i in range(0, 10, 1):
	print(ans[i], end="")
print()
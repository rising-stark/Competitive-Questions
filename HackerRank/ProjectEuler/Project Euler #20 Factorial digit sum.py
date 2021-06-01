import os
import sys

sys.stdin = open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/input.txt", "r")
sys.stdout = open("C:/Users/ujjwa/Desktop/Practice/code/Competitive-Questions/output.txt", "w")

t = int(input())
while(t>0):
	t-=1
	n = int(input())
	res = 1
	for i in range(n):
		res*=i+1
	sum = 0
	while(res>0):
		sum+=res%10
		res//=10
	print(sum)

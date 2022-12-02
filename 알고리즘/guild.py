import sys
sys.stdin = open("guildin.txt","r")

N = int(input())
data = list(map(int,input().split()))



data.sort()
result = 0
sum = 0
for i in data:
  sum = sum + i
  if sum >= N :
    result += 1
    sum=0

print(result)


import sys
sys.stdin = open("bollingin.txt","r")

N,M = map(int,input().split())
arr = list(map(int,input().split()))

DAT = [0]*(M+1)

for i in arr:
  DAT[i]+=1
result = 0
for i in range(1,M+1):
  for j in range(i+1,M+1):
    result += DAT[i]*DAT[j]

print(result)


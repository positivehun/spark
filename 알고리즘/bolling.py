import sys
sys.stdin = open("bollingin.txt","r")

N,M = map(int,input().split())
arr = list(map(int,input().split()))
count=0
for i in range(N):
  for j in range(i+1,N):
    if arr[i]!=arr[j]:
      count+=1

print(count)

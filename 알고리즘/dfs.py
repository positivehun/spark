import sys
sys.stdin = open("dfsin.txt","r")

N,M = map(int,input().split())
arr=[]
for _ in range(N):
  arr.append(list(map(int,input())))
d = [[1,0],[0,1]]
def dfs(i,j):
  if arr[i][j]==1:
    return
  arr[i][j]=1
  for k in range(2):
    di = i+d[k][0]
    dj = j+d[k][1]
    if di<4 and dj<5:
      dfs(di,dj)

cnt=0
for i in range(N):
  for j in range(M):
    if arr[i][j]==0:
      cnt+=1
      dfs(i,j)

print(cnt)


  


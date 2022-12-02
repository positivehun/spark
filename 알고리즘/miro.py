import sys
from queue import deque
sys.stdin = open("miroin.txt","r")
N,M = map(int,input().split())
arr=[]
for _ in range(N):
  arr.append(list(map(int,input())))

d = [[0,1],[1,0],[0,-1],[-1,0]]
def bfs(i,j):
  queue = deque()
  queue.append((i,j))
  while queue:
    i,j = queue.popleft()
    for k in range(4):
      di = i+d[k][0]
      dj = j+d[k][1]

      if di<0 or di>=N or dj<0 or dj>=M:
        continue

      if arr[di][dj]==0:
        continue
      if arr[di][dj]==1:
        arr[di][dj] = arr[i][j]+1
        queue.append((di,dj))

  return arr[N-1][M-1]

print(bfs(0,0))
for i in range(N):
  for j in range(M):
    print(arr[i][j],end=" ")
  print()


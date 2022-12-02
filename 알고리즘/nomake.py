import sys
sys.stdin = open("nomakein.txt","r")

N = int(input())

arr = list(map(int,input().split()))

arr.sort()

target = arr[0]
for i in arr:
  if target<i:
    break
  target+=i
print(target)

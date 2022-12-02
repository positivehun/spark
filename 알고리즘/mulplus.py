import sys
sys.stdin = open("mulplusin.txt","r")
N = int(input())

def mulplus(arr):

  result = int(arr[0])
  for i in range(1,len(arr)):
    if result == 0 or arr[i]=="0" or result==1 or arr[i]=="1":
      result += int(arr[i])
    else:
      result *= int(arr[i])
  return result


for _ in range(N):
  print(mulplus(list(input())))

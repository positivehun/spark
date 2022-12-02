import sys
sys.stdin = open("streversein.txt","r")

arr = input()

arr = list(arr)

count0 = 0 #전부 0으로 바꿀때 바꾼 횟수
count1 = 0 #전부 1로 바꿀때 바꾼 횟수

if arr[0]=="1":
  count0 +=1
else:
  count1 +=1

for i in range(len(arr)-1):
  if arr[i] !=arr[i+1]:
    if arr[i+1] == "1":
      count0+=1
    else:
      count1+=1

print(min(count0, count1))


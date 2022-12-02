def main(cnt):
  flag=0
  if cnt==10:
    return
  cnt +=1
  print(cnt,"번째 함수입니다")
  if cnt//2==0:
    flag=1
    main(cnt)
  if flag==0:
    print("main 재귀 실행안됨")
  else:
    print("main 재귀 실행 됨")


main(0)
  
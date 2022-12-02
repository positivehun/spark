#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Result(int l[20][4], int number); // 사다리타기 결과 구하는 함수

int main(void)
{
	printf(".");
	int a, b, c = 0;
	char re[5] = {"ABCDE"};
	int result[5][5] = {0};
	for (a = 0; a < 10000; a++)

	{
		// printf("1      2      3      4      5\n\n");
		int i, j, k, n;
		n = 0;
		int l[20][4] = {0}; //무작위의 사다리 생성을 위한 이차원 배열
		srand((unsigned int)time(NULL));
		for (i = 0; i < 20; i++)
		{
			// printf("|");
			for (j = 0; j < 4; j++)
			{
				k = rand() % 2; // 0 또는 1 중 무작위로 수 선정
				l[i][j] = k;		//배열 순서대로 무작위로 뽑은 수 입력

				if (l[i][j] == 1) //배열 중 1이 있을 때 가로선이 생기도록 if문 형성
				{
					if (i == 0) //첫번째 줄에는 가로선이 생기지 않도록 하기 위함
					{
						// printf("      |");
						l[i][j] = 0;
					}
					else
					{
						if (l[i][j - 1] == 1) //바로 왼쪽에 가로선이 있을 시, 예외 형성
						{
							// printf("      |");
							l[i][j] = 0;
						}
						else
						{
							if (l[i - 1][j] == 1) //바로 위에 가로선 있을 시, 예외 형성
							{
								// printf("      |"); // (가로선이 몰리는 것을 방지)
								l[i][j] = 0;
							}
							else
							{
								// printf("------|");
							}
						}
					}
				}
				else //배열 중 1이 아닌 0이면 가로선 형성x
				{
					// printf("      |");
				}
			}
			// printf("\n");
		}

		for (i = 0; i < 5; i++) // 최소 3개 이상의 가로선이 나오지 않으면 리셋.
		{
			for (j = 0; j < 20; j++)
			{
				if (l[j][i] == 1)
				{
					n++;
				}
			}
			if (n < 3)
			{
				// system("cls");
				main();
			}
			else
			{
				n = 0;
			}
		}

		// printf("\nA      B      C      D      E\n");
		// printf("\n\n결과: ");
		int number = 0;
		while (number < 5)
		{
			int ladder = Result(l, number);

			// 02468 -> ABCDE로 변경 후 결과 출력
			if (ladder == 0)
			{
				// printf("%d -> A ", number + 1);
				result[number][0]++;
			}
			else if (ladder == 2)
			{
				// printf("%d -> B ", number + 1);
				result[number][1]++;
			}
			else if (ladder == 4)
			{
				// printf("%d -> C ", number + 1);
				result[number][2]++;
			}
			else if (ladder == 6)
			{
				// printf("%d -> D ", number + 1);
				result[number][3]++;
			}
			else if (ladder == 8)
			{
				// printf("%d -> E ", number + 1);
				result[number][4]++;
			}
			number++;
		}
		// printf("\n");
   }
   // 반복 결과 출력
   for (b = 0; b < 5; b++)
   {
      printf("%d에서 시작했을 때 ", b+1);
      for (c = 0; c < 5; c++)
      {
         printf("%c 도착 %d회 ", re[c], result[b][c]);
      }
      printf("\n");
   }
}


int Result(int l[20][4], int number) //결과 구하는 함수
{
   int a, b, j; //for문을 위한 변수들
   int ladder = 0; //사다리게임의 진행
   int l_num[40][9] = { 0 };
   //결과를 쉽게 구하기 위해 가로 변수 사이에 0 삽입할 것. 4->9
   //change함수에서 길이가 늘어날 것을 대비해 열 40으로 설정

   for (a = 0; a < 20; a++) //홀수 열에만 (0 또는 1의)이차원 배열값 삽입
   {
      for (b = 0; b < 4; b++)
      {
         l_num[a][((2 * b) + 1)] = l[a][b];
      }
   }

   ladder = number * 2; //출발점 ABCDE -> int 배열에서 02468
   for (j = 0; j < 20; j++)
   {
      if (l_num[j][ladder + 1] == 1) //오른쪽에 가로선(배열 내 1)
      {
         ladder = ladder + 2; //오른쪽으로 두 칸 이동
      }
      else if (ladder != 0) //출발점이 1이면 왼쪽 없음
      {
         if (l_num[j][ladder - 1] == 1) //왼쪽에 가로선(배열 내 1)
         {
            ladder = ladder - 2; //왼쪽으로 두 칸 이동
         }
      }
   }
   return ladder;
}

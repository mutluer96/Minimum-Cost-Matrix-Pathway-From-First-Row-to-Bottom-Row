#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
	printf("Student ID: 152120191072 Name/Surname: Mucahid Mutluer\n");
	srand(time(NULL));
	int row, col;
	int i, j, m, n, min, min2;
	int upper = 9, lower = 0;
	int a[10][10];
	int c[10][10];
	int d[10][2];


	printf("Please insert the row size\n");
	scanf_s("%d", &row);
	printf("Please insert the colomn size\n");
	scanf_s("%d", &col);

	for (int i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)

		{
			a[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	printf("\n your matrix is :\n");
	for (m = 0; m < row ; m++)
	{
		for (n = 0; n < col; n++)
		{
			printf("%d\t", a[m][n]);
		}
		printf("\n");
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	printf(" * - * - * - * - * - * - * - * - * ");
	for (i = 0; i < row; i++)
	{
		if (i == 0)
			continue;
		for (j = 0; j < col; j++)
		{

			if (j == 0)
			{
				if (a[i - 1][j] < a[i - 1][j + 1])
				{
					min = a[i - 1][j];
				}
				else
				{
					min = a[i - 1][j + 1];
				}
				a[i][j] = a[i][j] + min;
			}
			else if (j == (col - 1))
			{
				if (a[i - 1][col - 2] < a[i - 1][col - 1])
				{
					min = a[i - 1][col - 2];
				}
				else
				{
					min = a[i - 1][col - 1];
				}
				a[i][j] = a[i][j] + min;
			}
			if ((j > 0) && (j < (col-1)))
			{
				{
					if (a[i - 1][j - 1] < a[i - 1][j])
					{
						min = a[i - 1][j - 1];
					}
					else
					{
						min = a[i - 1][j];
					}
				}
				if (min > a[i - 1][j + 1])
				{
					min = a[i - 1][j + 1];
				}
				a[i][j] = a[i][j] + min;

			}
		}
	}
	printf("\n your cost matrix is :\n");
	for (m = 0; m < row; m++)
	{
		for (n = 0; n < col; n++)
		{
			printf("%d\t", a[m][n]);
		}
		printf("\n");
	}
	int temp = a[row-1][0];
	for (i = 0; i < col; i++)
	{
		if (temp > a[row-1][i])
		{
			temp = a[row-1][i];
		}
	}
	printf("\n Your cost is %d\n", temp);
	int y;
	for (y = 0; y < col; y++)
	{
		if (a[row - 1][y] == temp)
		{
			break;
		}
	}
	d[row - 1][0] = row - 1;
	d[row - 1][1] = y;
	int k, l = y;
	min2 = 2147483647;
	for (k = row - 1; k > 0; k--)
	{

		if (l == 0)
		{
			if (a[k - 1][l] <= a[k - 1][l + 1])
			{
				min2 = l;
			}
			else
			{
				min2 = l + 1;
			}
		}
		if (l == (col - 1))
		{
			if (a[k - 1][l - 1] <= a[k - 1][l])
			{
				min2 = l - 1;
			}
			else
			{
				min2 = l;
			}

		}
		if ((l > 0) && (l < (col - 1)))
		{
			{
				{
					if (a[k - 1][l - 1] <= a[k - 1][l])
					{
						min2 = l - 1;
					}
					else
					{
						min2 = l;
					}
				}
				if (a[k - 1][min2] >= a[k - 1][l + 1])
				{
					min2 = l + 1;
				}
			}
		}
		d[k - 1][0] = k - 1;
		d[k - 1][1] = min2;
		l = min2;
	}
	printf("\n your pathway matrix is below \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((d[i][0] == i) && (d[i][1] == j))
			{
				printf(" [%d]\t", c[i][j]);
			}
			else
			{
				printf(" %d\t", c[i][j]);
			}
		}
		printf("\n");
	}
	
	system("pause");
}
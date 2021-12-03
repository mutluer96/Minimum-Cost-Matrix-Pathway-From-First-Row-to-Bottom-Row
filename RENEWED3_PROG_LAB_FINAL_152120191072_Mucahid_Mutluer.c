#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
	printf("Student ID:152120191072 Name: Mucahid Mutluer\n");
	srand(time(NULL));
	int i, j, row, col, min, min2;
	int upper = 9, lower = 0;
	printf("Please insert row size\n");
	scanf_s("%d", &row);
	printf("Please insert colomn size\n");
	scanf_s("%d", &col);
	int** arr = malloc(sizeof(int*)*row);


	for (i = 0; i < row; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*col);
		
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
	printf("\n*	*	*	*	*	*	*	*	*	*	*	\n");
	int** orj = malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++)
	{
		orj[i] = malloc(sizeof(int)*col);
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			orj[i][j] = arr[i][j];
		}
	}
	/*printf("\n\n your original matrix is below \n\n");
	for (i = 0; i < row; i++)
	{
	for (j = 0; j < col; j++)
	{
	printf(" %d\t", *(*(orj + i) + j));
	}
	printf("\n");
	}*/
	for (i = 0; i < row; i++)
	{
		if (i == 0)
			continue;
		for (j = 0; j < col; j++)
		{

			if (j == 0)
			{
				if (arr[i - 1][j] < arr[i - 1][j + 1])
				{
					min = arr[i - 1][j];
				}
				else
				{
					min = arr[i - 1][j + 1];
				}
				arr[i][j] = arr[i][j] + min;
			}
			else if (j == (col - 1))
			{
				if (arr[i - 1][col - 2] < arr[i - 1][col - 1])
				{
					min = arr[i - 1][col - 2];
				}
				else
				{
					min = arr[i - 1][col - 1];
				}
				arr[i][j] = arr[i][j] + min;
			}
			if ((j > 0) && (j < (col - 1)))
			{
				{
					if (arr[i - 1][j - 1] < arr[i - 1][j])
					{
						min = arr[i - 1][j - 1];
					}
					else
					{
						min = arr[i - 1][j];
					}
				}
				if (min > arr[i - 1][j + 1])
				{
					min = arr[i - 1][j + 1];
				}
				arr[i][j] = arr[i][j] + min;

			}
		}
	}
	printf("\n your cost matrix is below \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %d\t", *(*(arr + i) + j));
		}
		printf("\n");
	}
	int e;
	int temp = *(*(arr + row - 1) + 0);
	for (e = 0; e < col; e++)
	{
		if (*(*(arr + row - 1) + e) <= temp)
		{
			temp = *(*(arr + row - 1) + e);
		}
	}
	int y;
	for (y = 0; y < col; y++)
	{
		if (arr[row - 1][y] == temp)
		{
			break;
		}
	}
	printf("Your cost from top to the bottom row is %d ", temp);
	int** data = malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++) //dikkat!
	{
		data[i] = malloc(sizeof(int) * 2);
	}
	data[row - 1][0] = row - 1;
	data[row - 1][1] = y;
	int k, l = y;
	min2 = 2147483647;
	for (k = row - 1; k > 0; k--)
	{

		if (l == 0)
		{
			if (arr[k - 1][l] <= arr[k - 1][l + 1])
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
			if (arr[k - 1][l - 1] <= arr[k - 1][l])
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
					if (arr[k - 1][l - 1] <= arr[k - 1][l])
					{
						min2 = l - 1;
					}
					else
					{
						min2 = l;
					}
				}
				if (arr[k - 1][min2] >= arr[k - 1][l + 1])
				{
					min2 = l + 1;
				}
			}
		}
		data[k - 1][0] = k - 1;
		data[k - 1][1] = min2;
		l = min2;
	}
	printf("\n your pathway matrix is below \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((data[i][0] == i) && (data[i][1] == j))
			{
				printf(" [%d]\t", *(*(orj + i) + j));
			}
			else
			{
				printf(" %d\t", *(*(orj + i) + j));
			}
		}
		printf("\n");
	}
	system("pause");
}
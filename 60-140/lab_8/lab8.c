#include <stdio.h>

void ReadData(int[3][6]);
void RowCalc(int[3][6]);
void ColumnCalc(int[3][6]);

int main(void)
{
	int numTable[3][6];

	ReadData(numTable);
	printf("\n\n");
	RowCalc(numTable);
	printf("\n\n");
	ColumnCalc(numTable);
	printf("\n\n");
	return 0;
}

void ReadData(int table[3][6])
{
	int r, c;
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 6; c++)
		{
			scanf("%d", &table[r][c]);
		}
	}	

}

void RowCalc(int table[3][6])
{
	int r, c, sum, min;
	float ave;
	for (r = 0; r < 3; r++)
	{
		min = table[r][0];
		sum = 0;
		for (c = 0; c < 6; c++)
		{
			sum += table[r][c];
			printf("%d ", table[r][c]);
			if (table[r][c] < min)
			{
				min = table[r][c];
			}
		}

		ave = sum/6;
		printf(" Min %d Ave %0.2f\n", min, ave);
	}	
}

void ColumnCalc(int table[3][6])
{
	int r, c, sum, min;
	float ave;
	for (c = 0; c < 6; c++)
	{
		min = table[0][c];
		sum = 0;
		for (r = 0; r < 3; r++)
		{
			sum += table[r][c];
			printf("%d ", table[r][c]);
			if (table[r][c] < min)
			{
				min = table[r][c];
			}
		}
		ave = sum/6;
		printf("Col Min %d Col Ave %0.2f\n", min, ave);	
	}	
}

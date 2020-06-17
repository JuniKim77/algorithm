#include <stdio.h>
#define OBJECT 8

int bottleSize[4] = { 0, 10, 5, 6 };
int waterSize[4] = { 0, 5, 0, 6 };

void printOut(void);
char* emptyBottle = "|     |";
char* waterBottle = "|-----|";
char* BottomBottle = "+-----+";

int main(void)
{
	do
	{
		int from = 0;
		int to = 0;
		int sum = 0;
		printOut();
		printf("\nEnter a command: ");

		scanf_s("%d %d", &from, &to);

		sum = waterSize[from] + waterSize[to];
		if (sum > bottleSize[to])
		{
			waterSize[to] = bottleSize[to];
			sum -= bottleSize[to];
			waterSize[from] = sum;
		}
		else
		{
			waterSize[to] = sum;
			waterSize[from] = 0;
		}
	} while (waterSize[1] != OBJECT);
	
	printOut();
	printf("\nCongratulations! You've got 8-liter water!");

	return 0;
}


void printOut(void)
{
	int i = 0;
	printf("\n");
	for (i = 10; i > 6; --i)
	{
		if (waterSize[1] == i)
		{
			printf("%s\n", waterBottle);
		}
		else
		{
			printf("%s\n", emptyBottle);
		}
	}
	printf("%s           %s\n", waterSize[1] == 6 ? waterBottle : emptyBottle, waterSize[3] == 6 ? waterBottle : emptyBottle);

	for (int i = 5; i > 0; --i)
	{
		printf("%s  %s  %s\n", waterSize[1] == i ? waterBottle : emptyBottle, 
			waterSize[2] == i ? waterBottle : emptyBottle,
			waterSize[3] == i ? waterBottle : emptyBottle);
	}

	printf("%s  %s  %s\n", BottomBottle, BottomBottle, BottomBottle);
}
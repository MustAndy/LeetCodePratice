#include <stdio.h>

int main()
{
	char judge = 'Y';//variable to judge whether continue
	while(judge == 'Y')//judge whether continue
	{
		//initialize array for input, array size, the row and column parameter
		int inputArray[100][100];
		int row = 0;
		int column = 0;
		int arraysize = 3;

		printf("Before transpose:\n");//prompt
	
		//read data from user and put data in two-dimensional array
		while(true)
		{
			scanf("%d",&inputArray[column][row++]);
			if(getchar() == '\n')//if line feed, put data into next column
			{
				arraysize = row;//set array size
				column++;//put data in new line
				row = 0;//put data in first element in new line
			}
			if(column == arraysize)//if input complete, break
			{
				column--;//put column to the last column
				row = arraysize - 1;//put row to the last element of last column
				break;
			}
		}

		printf("After transpose:\n");//prompt
	
		//print out array after transpose
		while(true)
		{
			printf("%d\t",inputArray[column][row--]);//print out data from last element of last column
			if(row == -1)//if all element in line have been output, put row to last element of last column
			{
				printf("\n");//line feed
				column--;
				row = arraysize - 1;
			}
			if(column == -1)//if all line have been output, break
				break;
		}

		printf("Continue? (Y/N) ");//prompt user whether continue
		judge = getchar();
	}	
	return 0;
}

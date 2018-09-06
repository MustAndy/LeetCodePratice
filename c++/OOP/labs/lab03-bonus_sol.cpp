#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand( time( NULL ));//initialize srand() function

	//initialize 9*9 map, random column number and random row number
	char mineMap[9][9];
	int randomColumn = 0;
	int randomRow = 0;

	//initialize 9*9m map with '.'
	for(int controlColumn = 0; controlColumn < 9; controlColumn++)//column by column
		for(int controlRow = 0; controlRow < 9; controlRow++)//element by element in a row
			mineMap[controlColumn][controlRow] = '.';

	//put random mine into map
	for(int mineNumber = 0; mineNumber < 10; mineNumber++)//put 10 mine
	{
		randomColumn = rand() % 9;//get random column number
		randomRow = rand() % 9;//get randow row number
		while(mineMap[randomColumn][randomRow] == '*')//if there already has a mine, re-generate random column and row
		{
			randomColumn = rand() % 9;
			randomRow = rand() % 9;
		}
		mineMap[randomColumn][randomRow] = '*';//if there is no mine, put a mine in the map
	}

	printf("The mine map without hints:\n");//prompt

	//print out map with mine and without hints
	for(int controlColumn = 0; controlColumn < 9; controlColumn++)
	{
		for(int controlRow = 0; controlRow < 9; controlRow++)//column by column
		{
			printf("%c ", mineMap[controlColumn][controlRow]);//element by element in a row
		}
		printf("\n");//after printing a row, line feed
	}

	//put hints in the map
	for(int controlColumn = 0; controlColumn < 9; controlColumn++)//column by column
	{
		for(int controlRow = 0; controlRow < 9; controlRow++)//element by element in a row
		{
			if(mineMap[controlColumn][controlRow] == '*')//when find a mine, then put integer around the mine
			{
				int column = controlColumn - 1;//put column to the last column before this mine
				int row = controlRow - 1;//put row before mine

				for( column; column < controlColumn + 2; column++)//add hints around mine
				{
					if( column < 0 || column > 8 )//if mine is on the topside, next column
						continue;
					for( row; row < controlRow + 2; row++)//add hints around mine
					{
						if( row < 0 )//if mine is on the leftmost, next row
							continue;
						if( row >= 9 )
							break;
						if(mineMap[column][row] == '*')//if there is a mine, next row
							continue;
						if(mineMap[column][row] >= '0' && mineMap[column][row] <= '9')//if there is a digit, plus 1
						{
							mineMap[column][row]++;
							continue;
						}
						if(mineMap[column][row] == '.')//if there is empty space, put 1 into map
						{
							mineMap[column][row] = '1';
							continue;
						}
					}
					row = controlRow - 1;//row come back before mine
				}
			}
		}
	}

	printf("\nThe mine map with hints:\n");//prompt

	//print out map with mine and hints
	for(int controlColumn = 0; controlColumn < 9; controlColumn++)
	{
		for(int controlRow = 0; controlRow < 9; controlRow++)
		{
			printf("%c ", mineMap[controlColumn][controlRow]);
		}
		printf("\n");
	}

    for (;;);
	return 0;
}

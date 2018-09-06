#include <stdio.h>
#include <math.h>

int main()
{
	char judge = 'Y';//variable to judge whether continue calculating next array
	int tasktime = 1;//task number
	while(judge == 'Y')//judge whether continue
	{
		//initialize input array, array size, sum of array, average of array, standard deviation of array
		double inputArray[100];
		int size = 0;
		double sum = 0.0;
		double average = 0.0;
		double stdDev = 0.0;

		//prompt user to enter array element and read data
		printf("Please enter the array (The element seperated by the space) :\n");
		do
		{
			scanf("%lf",&inputArray[size++]);
		}
		while(getchar()!= '\n');
	
		//calculate average of array
		for(int control = 0; control < size; control++)
			sum += inputArray[control];
		average = sum / size;

		//calculate standard deviation of array
		for(int control = 0; control < size; control++)
			stdDev += (inputArray[control] - average) * (inputArray[control] - average) / size;

		//print out result
		printf("Task %d:\n"
			"The Average of this array: %.2lf\n"
				"The Standard Deviation of this array: %.4lf\n", tasktime, average, sqrt(stdDev));
		
		//ask whether continue enter array
		printf("Continue? (Y/N) ");
		judge = getchar();
		
		tasktime++;//next task number
	}
	return 0;
}

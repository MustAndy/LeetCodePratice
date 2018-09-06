#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	while(1){
	int balance;
cout << "Please input the amount of money: ";
scanf("%d",&balance);
int i = balance/500;
int j = balance%500/100;
printf("No. of $500 notes: %d\n",i);
printf("No. of $100 notes: %d\n",j);
	}
return 0;
}

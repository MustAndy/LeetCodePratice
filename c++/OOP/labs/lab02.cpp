#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>              // contains the random number generator rand() 
#include <ctime>                // contains time() to seed the random number 
                                // generator to gives a different answer each time
using namespace std;

// Function prototypes
// Please complete the function definitions in the later part of this file
int findRoots(double a, double b, double c, double &r1, double &r2);
void task1();
void task2();

// DO NOT Modify the given code
int main()
{
	int number;
    
    while(true)
	{
		cout << "Please enter a number (1-2) for the tasks (-1 to quit):";
		cin >> number;

		if(number==-1)
		{
			cout << "Mission completed!" << endl; 
			break; 
		}
		if(number==1) 
			task1();
		else if(number==2) 
			task2();
		else cout <<"Invalid number, please input again.\n";
	}

	return 0;
}

// DO NOT Modify the given code
void task1()
{
    int code1, code2, code3;            // computer's digits 
	int correct = 0, pos = 0;
	int pcor1 = 0, pcor2 = 0, pcor3 = 0;
	int step = 1;
	int guess1, guess2, guess3;

    srand(time(0));                // initialize random number generator 

    code1 = rand()%7 + 1;             // picks random value between 1 and 7 
    code2 = rand()%7 + 1;             // picks random value between 1 and 7 
    code3 = rand()%7 + 1;             // picks random value between 1 and 7 
    
    // Please complete the rest of program 

}

// DO NOT Modify the given code
void task2()
{
	cout << "Task 1: find roots" << endl;
	double a, b, c, r1, r2;
    int count;
    cout << "Please input cooefficients a, b, and c" << endl;
    cin >> a >> b >> c;
  
    count = findRoots(a, b, c, r1, r2);

    if (count == 0) 
	    cout << "There is no real roots in this equation" << endl;
    else if (count == 1) 
	    cout << "There is a single root: " << r1 << endl;
    else cout << "There are two real roots: " << r1 << " " << r2 << endl;
}

/********************************************************************
 *
 * Description:
 *   Method to compute the the number of real roots and
 *   the values of these roots for a quadratic equation. 
 *
 * Parameters:
 * input:  a, b, c
 * reference parameters: r1 r2
 *
 * Return:
 *   rootCount: the number of real roots
 *   0: no real roots
 *   1: one real root
 *   2: two real roots
 *
 ********************************************************************/
int findRoots(double a, double b, double c, double &r1, double &r2)
{
// Please write your code as follows

}



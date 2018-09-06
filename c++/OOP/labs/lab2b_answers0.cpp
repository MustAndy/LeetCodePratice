#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
void task1() {
	printf("Task 1:\nGuess Number Game\nEnter three digits(1-7) sparated by a space\n-----------------------------------------------\n");
	srand((unsigned int)time(NULL));
	int d[] = { rand() % 7 + 1,rand() % 7 + 1,rand() % 7 + 1 };
	int g[] = { 0,0,0 };
	for (int i = 1;; i++) {

		int t = 0;
		char c[3];
		printf("Round %d\n", i);
		printf("Enter Guess:\n");
		scanf("%d %d %d", &g[0], &g[1], &g[2]);
		for (int z = 0; z < 3; z++) {
			if (d[z] == g[z]) { t++; c[z] = 'R'; }
			else c[z] = ' ';
		}
		printf("You guess %d digit(s) right\n", t);
		if (t == 3) {
			printf("Congratulations! You win in step %d", i);
			break;
		}
		printf("%c %c %c\n", c[0], c[1], c[2]);
	}
}
float* findRoots(float a, float b, float c) {
	float *x = new float[2];
	x[1] = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
	x[0] = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
	return x;
}
void task2() {
	float a, b, c;
	printf("Task 2: find roots\n");
	printf("Please input cooefficients a, b, and\nc ");
	scanf("%f %f %f", &a, &b, &c);

	float *x = { findRoots(a, b, c) };
	if (x[0] == x[1]) {
		printf("There is a single root: %.2f", x[0]);
	}
	else {
		printf("There are two real roots: %.2f  %.2f", x[0], x[1]);
	}
}
int main() {
	task2();
	printf("\n");
	task1();
}

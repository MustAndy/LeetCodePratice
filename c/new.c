

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int a, int b)
{
  if (b == 0)
    return 0;
  if (b % 2 == 0)
  {
    printf("%d\n", b);
    return foo(a + a, b / 2);
  }
  printf("a:%d\n", a);
  return foo(a + a, b / 2) + a;
}
void main()
{
  printf("%d", foo(1, 3));
}


#include <stdio.h>
int f(float);
float g(int);
int h(int*);

void main()
{
   /* FUNCTIONS */
   int a = 7;
   printf("%d %d %d %d", f(g(2)), a, h(&a), a);
}

int f(float a)
{  return (int)(a * g(4));  }

float g(int a)
{  return (float)(h(&a) + a);  }

int h(int *a)
{  return ++(*a);  }

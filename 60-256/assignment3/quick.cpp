#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	   unsigned int  i;
		    srand(45);    
		FILE *fp = fopen("input.dat", "w");                        
		       for (int k = 1;k <= 20; ++k)
		       {
			  fprintf(fp, "%d", (rand() % 100 + 1));
		          for( i = 1 ; i <= 10 ; ++i)
			  {
				fprintf(fp, " %d", (rand() % 100 + 1));;
			  }
			  fprintf(fp, "\n");
		       }
			     return 0;
} 


/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 4
******************************************/

#include <stdio.h>
#include <string.h>
#include "Matritza.h"
#include "PigLatin.h"

#define MAX_CHAR 15
#define SIZE_MAT 15

int main()
{
	char str[MAX_CHAR];
	int runningFlag = 1, len = 0;
	char dummy;

	while (runningFlag)
	{
		printf("Main menu, choose between the options:\n");
		printf("Matrix Calculator\n");
		printf("PigLatin Translator \n");
		
		fgets(str, MAX_CHAR, stdin);
		ConvertToLowCase(str);
		len = strlen(str);
		str[len - 1] = '\0';

		if (strcmp(str, "calculator") == 0)
		{
			MainMatrix();
			scanf("%c", &dummy);
		}
		else if (strcmp(str, "translator") == 0)
		{
			PigLatin();
		}
		else if (strcmp(str, "quit") == 0)
		{
			return 0;
		}
		else
		{
			printf("This was not an option.\n");
			continue;
		}
	}
			
	
}





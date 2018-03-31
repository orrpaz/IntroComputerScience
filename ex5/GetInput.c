/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GetInput.h"

/************************************************************************
* function name: GetNewSring
* The Input: numMission type int
* The output: return pointer type char* (ptr)
* The Function operation: the function allocate memory and
then getstring from user.
*************************************************************************/
char* GetNewSring(int numMission)
{
	int size;
	char *ptr;
	char dummy;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &size);
	ptr = (char*)malloc((size) * sizeof(char));
	// if it didnt success
	if (ptr == NULL)
	{
		printf("Error:Cannot allocate Memory\n");
		return NULL;
	}
	printf("Allocated %d chars\n", size);

	if (numMission == 1)
		// for mission 1
		printf("Please enter string to be sorted:\n");
	else
		printf("Please enter your string:\n");
	scanf("%c", &dummy);
	fgets(ptr, size, stdin);
	ptr[size - 1] = '\0';
	return ptr;
}

/************************************************************************
* function name: Get2Srting
* The Input: char **str, char **sub
* The output: none
* The Function operation: the function get from user 2 size and then
2 string in the same size - 1.
*************************************************************************/
void Get2Srting(char **str, char **sub)
{
	int size, size2;
	printf("Please enter how many chars to allocate to the two strings:\n");
	scanf("%d %d", &size, &size2);
	*str = (char*)malloc((size) * sizeof(char));
	// if it didnt success
	if (*str == NULL)
	{
		printf("Error:Cannot allocate Memory\n");
		return;
	}
	*sub = (char*)malloc((size2) * sizeof(char));
	if (*sub != NULL)
	{
		printf("Allocated %d chars and %d chars\n", size, size2);
	}
	// if it didnt success
	else
	{
		printf("Error:Cannot allocate Memory\n");
		free(*str);
		return;
	}
	printf("Please enter two arrays of chars:\n");
	scanf("%s %s", *str, *sub);

}